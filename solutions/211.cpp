class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() {
        this->children = vector<TrieNode*>(26, nullptr);
        this->isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string& word) {
        TrieNode* node = root;
        for (auto& c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    bool search(string& word, int index) {
        TrieNode* node = root;
        return _search(root, word, index);
    }
    bool _search(TrieNode* node, string& word, int index) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char c = word[index];
        if (c == '.') {
            for (int j = 0; j < 26; ++j) {
                if (node->children[j] && _search(node->children[j], word, index + 1)) {
                    return true;
                }
            }
            return false;
        }
        else {
            if (node->children[c - 'a'] == nullptr) return false;
            return _search(node->children[c - 'a'], word, index + 1);
        }
    }
};
class WordDictionary {
public:
    Trie* trie;
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */