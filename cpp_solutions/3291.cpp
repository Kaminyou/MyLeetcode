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
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string& s) {
        int n = s.size();
        TrieNode* curr = root;
        for (int i = 0; i < n; ++i) {
            if (curr->children[s[i] - 'a'] == nullptr) {
                curr->children[s[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[s[i] - 'a'];
        }
        curr->isEnd = true;
    }
    int search(string& s, int start) {
        int res = 0;
        int n = s.size();
        TrieNode* curr = root;
        for (int i = start; i < n; ++i) {
            if (curr->children[s[i] - 'a'] == nullptr) {
                return i - start;
            }
            curr = curr->children[s[i] - 'a'];
        }
        return n - start;
    }
};
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie* trie = new Trie();
        for (auto& word : words) trie->insert(word);
        int n = target.size();
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int length = trie->search(target, i - 1);
            for (int j = 0; j < length; ++j) {
                dp[i + j] = min(dp[i + j], dp[i - 1] + 1);
            }
        }
        if (dp[n] == INT_MAX / 2) return -1;
        return dp[n];
    }
};
