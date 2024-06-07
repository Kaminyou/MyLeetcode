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
    void insert(string &s) {
        TrieNode* current = root;
        for (auto &c : s) {
            if (!current->children[c - 'a']) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEnd = true;
    }
    int search(string& s) {
        TrieNode* current = root;
        int res = 0;
        for (auto &c : s) {
            if (!current->children[c - 'a']) return -1;
            current = current->children[c - 'a'];
            res += 1;
            if (current->isEnd) return res;
        }
        return res;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for (auto& word : dictionary) {
            trie->insert(word);
        }
        stringstream ss(sentence);
        string token;
        string res = "";
        while (getline(ss, token, ' ')) {
            int index = trie->search(token);
            if (index != -1) {
                string substring = token.substr(0, index);
                res += substring;
            }
            else {
                res += token;
            }
            res += " ";
        }
        res.pop_back();
        return res;
    }
};
