class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for (auto& query : queries) {
            for (auto& word : dictionary) {
                int diff = 0;
                int n = query.size();
                for (int i = 0; i < n; ++i) {
                    if (query[i] != word[i]) diff++;
                }
                if (diff <= 2) {
                    res.push_back(query);
                    break;
                }
            }
        }
        return res;
    }
};

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() {
        children.resize(26, nullptr);
        isEnd = false;
    }
};
class Trie {
private:
    TrieNode* root = nullptr;
public:
    Trie() {
        root = new TrieNode();
    }
    void add(string s) {
        TrieNode* node = root;
        for (auto& c : s) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    bool find(string s) {
        TrieNode* node = root;
        return _find(s, 0, node, 0);
    }
    bool _find(string& s, int index, TrieNode* node, int cnt) {
        if (cnt > 2) return false;
        if (index == s.size() && node->isEnd) return true;
        bool feasible = false;
        if (node->children[s[index] - 'a']) {
            if (_find(s, index + 1, node->children[s[index] - 'a'], cnt)) feasible = true;
        }
        if (!feasible) {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] != nullptr && _find(s, index + 1, node->children[i], cnt + 1)) {
                    feasible = true;
                    break;
                }
            }
        }
        return feasible;
    }
};

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        Trie* trie = new Trie();
        for (auto& s : dictionary) {
            trie->add(s);
        }
        vector<string> res;
        for (auto& q : queries) {
            if (trie->find(q)) res.push_back(q);
        }
        return res;
    }
};
