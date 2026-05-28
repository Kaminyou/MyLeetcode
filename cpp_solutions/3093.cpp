class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd = false;
    int bestIndex = INT_MAX;
    int length = INT_MAX;
    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
private:
    int globalMaxLength;
    TrieNode* root = nullptr;
public:
    Trie(int allMaxLength) {
        root = new TrieNode();
        globalMaxLength = allMaxLength;
    }
    void insert(string& s, int index) {
        int currLength = s.size();
        TrieNode* node = root;
        int idx = 0;
        for (auto& c : s) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
            if (currLength == node->length) {
                if (index < node->bestIndex) {
                    node->bestIndex = index;
                }
            }
            if (currLength < node->length) {
                node->bestIndex = index;
                node->length = currLength;
            }
            idx++;
            if (idx > globalMaxLength) break;
        }
        node->isEnd = true;
    }
    int find(string& s) {
        TrieNode* node = root;
        for (auto& c : s) {
            if (!node->children[c - 'a']) break;
            node = node->children[c - 'a'];
        }
        return node->bestIndex;
    }
    void setBestIndex(int index) {
        root->bestIndex = index;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int allMaxLength = 0;
        for (auto& s : wordsQuery) {
            allMaxLength = max(allMaxLength, (int)s.size());
        }
        Trie* trie = new Trie(allMaxLength);
        int minLength = INT_MAX;
        int n = wordsContainer.size();
        for (int i = 0; i < n; ++i) {
            reverse(wordsContainer[i].begin(), wordsContainer[i].end());
            trie->insert(wordsContainer[i], i);
            if (wordsContainer[i].size() < minLength) {
                trie->setBestIndex(i);
                minLength = wordsContainer[i].size();
            }
        }
        int m = wordsQuery.size();
        vector<int> res(m, -1);
        for (int i = 0; i < m; ++i) {
            reverse(wordsQuery[i].begin(), wordsQuery[i].end());
            res[i] = trie->find(wordsQuery[i]);
        }
        return res;
    }
};
