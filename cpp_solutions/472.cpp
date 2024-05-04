class Solution {
public:
    vector<string> res;
    unordered_set<string> st;
    unordered_set<string> visited;
    void backtracking(const string& s, int curr, int count) {
        if (curr == s.size()) {
            if (count >= 2 && visited.find(s) == visited.end()) {
                res.push_back(s);
                visited.insert(s);
            }
            return;
        }
        string temp;
        for (int i = curr; i < s.size(); ++i) {
            temp.push_back(s[i]);
            if (st.find(temp) != st.end()) backtracking(s, i + 1, count + 1);
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto& word : words) st.insert(word);
        for (auto& word : words) {
            backtracking(word, 0, 0);
        }
        return res;
    }
};

// v2
class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd = false;
    TrieNode() {
        children.resize(26, nullptr);
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string& s) {
        TrieNode* current = root;
        for (auto& c : s) {
            if (!(current->children[c - 'a'])) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEnd = true;
    }
    int traverse(string& s, int index, int depth) {
        if (index == s.size()) {
            return 0;
        }
        TrieNode* current = root;
        for (int i = index; i <= s.size(); ++i) {
            if (current->isEnd) {
                int res = traverse(s, i, depth + 1);
                if (res != -1) return res + 1;
            }
            if (i == s.size()) return -1;
            if (!(current->children[s[i] - 'a'])) return -1;
            current = current->children[s[i] - 'a'];
        }
        return -1;
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie* trie = new Trie();
        for (auto& word : words) {
            trie->insert(word);
        }
        vector<string> res;
        for (auto& word : words) {
            int count = trie->traverse(word, 0, 0);
            if (count >= 2) res.push_back(word);
        }
        return res;
    }
};