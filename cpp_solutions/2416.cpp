class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    int numOfSubNodes;
    TrieNode () {
        memset(children, 0, sizeof(children));
        isEnd = false;
        numOfSubNodes = 0;
    }
    
};
class Trie {
public:
    TrieNode* root;
    Trie () {
        root = new TrieNode();
    }
    void insert(string& s) {
        TrieNode* current = root;
        for (auto& c : s) {
            if (current->children[c - 'a'] == nullptr) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
            current->numOfSubNodes++; // important
        }
        current->isEnd = true;
    }
    int traverse(string& s) {
        int count = 0;
        TrieNode* current = root;
        for (auto& c : s) {
            current = current->children[c - 'a'];
            count += current->numOfSubNodes;
        }
        return count;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for (auto& word : words) trie->insert(word);
        int n = words.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            res[i] = trie->traverse(words[i]);
        }
        return res;
    }
};
