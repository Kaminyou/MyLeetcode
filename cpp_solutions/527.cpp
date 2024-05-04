class TrieNode {
public:
    vector<TrieNode*> children;
    int isEnd;
    int passNum;
    TrieNode() {
        children.resize(26, nullptr);
        isEnd = -1;
        passNum = 0;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string& s, int index) {
        TrieNode* curr = root;
        for (auto& c : s) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr->passNum++;
            curr = curr->children[c - 'a'];
        }
        curr->passNum++;
        curr->isEnd = index;
    }
    void _goToEnd(vector<string>& res, string& fullpath, string& path, TrieNode* curr, int start, int depth) {
        if (curr->isEnd != -1) {
            if (start + 2 >= depth) res[curr->isEnd] = fullpath;
            else {
                int diff = depth - start - 1;
                res[curr->isEnd] = path + to_string(diff) + fullpath[fullpath.size() - 1];
            }
            return;
        }
        for (int i = 0; i < 26; ++i) {
            if (curr->children[i] != nullptr) {
                fullpath.push_back(i + 'a');
                _goToEnd(res, fullpath, path, curr->children[i], start, depth + 1);
                fullpath.pop_back();
                break;
            }
        }
    }
    void _dfs(vector<string>& res, string& fullpath, string& path, TrieNode* curr, int depth) {
        if (curr->passNum == 1) {
            _goToEnd(res, fullpath, path, curr, depth, depth);
            return;
        }
        for (int i = 0; i < 26; ++i) {
            if (curr->children[i] != nullptr) {
                path.push_back(i + 'a');
                fullpath.push_back(i + 'a');
                _dfs(res, fullpath, path, curr->children[i], depth + 1);
                fullpath.pop_back();
                path.pop_back();
            }
        }
    }
    void dfs(vector<string>& res, string& fullpath, string& path) {
        _dfs(res, fullpath, path, root, 0);
    }
};
class Solution {
public:
    string toAbbrev(string& s) {
        int n = s.size();
        if (n <= 3) return s;
        int mid = n - 2;
        return s[0] + to_string(mid) + s[n - 1];
    }
    vector<string> wordsAbbreviation(vector<string>& words) {
        int n = words.size();
        unordered_map<string, vector<pair<string, int>>> hash2origin;
        for (int i = 0; i < n; ++i) {
            string& word = words[i];
            string abbrev = toAbbrev(word);
            hash2origin[abbrev].push_back(make_pair(word, i));
        }
        vector<string> res(n);
        for (auto& element : hash2origin) {
            if (element.second.size() == 1) {
                res[element.second[0].second] = element.first;
            }
            else {
                Trie* trie = new Trie();
                for (auto& [word, idx] : element.second) {
                    trie->insert(word, idx);
                }
                string fullpath = "";
                string path = "";
                trie->dfs(res, fullpath, path);
            }
        }
        return res;
    }
};