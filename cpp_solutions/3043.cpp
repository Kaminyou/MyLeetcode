class TrieNode {
public:
    vector<TrieNode*> children;
    TrieNode() {
        children.resize(10, nullptr);
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string& s) {
        int n = s.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; ++i) {
            if (!cur->children[s[i] - '0']) {
                cur->children[s[i] - '0'] = new TrieNode();
            }
            cur = cur->children[s[i] - '0'];
        }
    }
    int maxDepth(string& s) {
        int n = s.size();
        TrieNode* cur = root;
        int depth = 0;
        for (int i = 0; i < n; ++i) {
            if (!cur->children[s[i] - '0']) break;
            cur = cur->children[s[i] - '0'];
            depth = i + 1;
        }
        return depth;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* trie = new Trie();
        for (auto& num : arr1) {
            string s = to_string(num);
            trie->insert(s);
        }
        int maxDepth = 0;
        for (auto& num : arr2) {
            string s = to_string(num);
            int depth = trie->maxDepth(s);
            maxDepth = max(depth, maxDepth);
        }
        return maxDepth;
    }
};
