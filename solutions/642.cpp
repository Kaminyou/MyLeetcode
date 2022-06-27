class TrieNode {
public:
    vector<TrieNode*> children;
    int isEnd;
    TrieNode() {
        children.resize(27, nullptr);
        isEnd = 0;
    }
};
class Trie {
private:
    TrieNode* root;
    TrieNode* searchCurr;
    bool searchFlag = true;
    string searchPath;
public:
    Trie() {
        root = new TrieNode();
        searchCurr = root;
        searchPath = "";
    }
    int char2idx(char c) {
        if (c == ' ') return 26;
        return c - 'a';
    }
    int idx2char(int i) {
        if (i == 26) return ' ';
        return i + 'a';
    }
    void insert(string& s, int hot) {
        TrieNode* curr = root;
        for (auto& c : s) {
            if (curr->children[char2idx(c)] == nullptr) {
                curr->children[char2idx(c)] = new TrieNode();
            }
            curr = curr->children[char2idx(c)];
        }
        curr->isEnd += hot;
    }
    void search_(TrieNode* curr, vector<pair<int, string>>& res, const string& searchPath, string& path) {
        if (curr == nullptr) return;
        if (curr->isEnd > 0) {
            res.push_back(make_pair(curr->isEnd, searchPath + path));
        }
        for (int i = 0; i < 27; ++i) {
            if (curr->children[i] != nullptr) {
                path.push_back(idx2char(i));
                search_(curr->children[i], res, searchPath, path);
                path.pop_back();
            }
        }
    }
    vector<pair<int, string>> search(char next) {
        vector<pair<int, string>> res;
        if (!searchFlag || searchCurr->children[char2idx(next)] == nullptr) {
            searchFlag = false;
            return res;
        }
        searchPath.push_back(next);
        searchCurr = searchCurr->children[char2idx(next)];
        string path = "";
        search_(searchCurr, res, searchPath, path);
        return res;
    }
    void resetSearch(string& s) {
        insert(s, 1);
        searchCurr = root;
        searchFlag = true;
        searchPath = "";
    }
};
class AutocompleteSystem {
public:
    Trie* trie;
    string inputString;
    static bool compare(const pair<int, string>& p1, const pair<int, string>& p2) {
        if (p1.first != p2.first) return p1 > p2;
        return p1.second < p2.second;
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();
        int n = times.size();
        for (int i = 0; i < n; ++i) {
            trie->insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<pair<int, string>> res;
        if (c == '#') {
            trie->resetSearch(inputString);
            inputString = "";
            vector<string> empty;
            return empty;
        }
        inputString.push_back(c);
        res = trie->search(c);
        sort(res.begin(), res.end(), compare);
        
        vector<string> ans;
        int n = res.size();
        for (int i = 0; i < min(3, n); ++i) {
            ans.push_back(res[i].second);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */