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
    
    void insert(string word) {
        TrieNode* current = root;
        for (auto c : word) {
            if (!current->children[c - 'a']) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for (auto c : word) {
            if (!current->children[c - 'a']) {
                return false;
            }
            current = current->children[c - 'a'];
        }
        return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (auto c : prefix) {
            if (!current->children[c - 'a']) {
                return false;
            }
            current = current->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */