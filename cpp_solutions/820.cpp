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
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string& s) {
        TrieNode* curr = root;
        for (auto& c : s) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }
    void dfs(TrieNode* node, int currLength, int& count, int& length) {
        bool noChildren = true;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                dfs(node->children[i], currLength + 1, count, length);
                noChildren = false;
            }
        }
        if (noChildren) {
            count++;
            length += currLength;
        }
    }
    int encode() {
        int count = 0;
        int length = 0;
        dfs(root, 0, count, length);
        return length + count;
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* trie = new Trie();
        for (auto& word : words) {
            reverse(word.begin(), word.end());
            trie->insert(word);
        }
        return trie->encode();
    }
};