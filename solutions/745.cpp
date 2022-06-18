class TrieNode {
public:
    vector<TrieNode*> children;
    int isEnd;
    TrieNode() {
        children.resize(27);
        isEnd = -1;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    int char2idx(char c) {
        if (c == '#') return 26;
        return c - 'a';
    }
    void insert(string& s, int index) {
        TrieNode* curr = root;
        for (auto& c : s) {
            int idx = char2idx(c);
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = index;
    }
    void dfs(TrieNode* node, int& res) {
        if (node->isEnd >= 0) res = max(res, node->isEnd);
        for (auto& child : node->children) {
            if (child != nullptr) dfs(child, res);
        }
    }
    void _search(string& s, int& res) {
        TrieNode* curr = root;
        for (auto& c : s) {
            int idx = char2idx(c);
            if (curr->children[idx] == nullptr) return;
            curr = curr->children[idx];
        }
        dfs(curr, res);
    }
    int search(string& s) {
        int res = -1;
        _search(s, res);
        return res;
    }
};

class WordFilter {
public:
    Trie* trie;
    WordFilter(vector<string>& words) {
        trie = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            string& word = words[i];
            for (int j = 0; j < word.size(); ++j) {
                string extend = word.substr(j) + "#" + word;
                trie->insert(extend, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string query = suffix + "#" + prefix;
        return trie->search(query);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */