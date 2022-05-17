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
    vector<pair<int, int>> directions;
    TrieNode* root;
    Trie() {
        root = new TrieNode();
        directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    }
    void insert(string word) {
        TrieNode* curr = root;
        for (auto c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }
    void backtracking(int x, int y, vector<vector<char>>& board, vector<string>& res, string& path, int M, int N) {
        TrieNode* curr = root;
        char c = board[x][y];
        if (curr->children[c - 'a'] != nullptr) {
            board[x][y] = '#';
            path.push_back(c);
            if (curr->children[c - 'a']->isEnd) {
                res.push_back(path);
                curr->children[c - 'a']->isEnd = false;
            }
            _backtracking(curr->children[c - 'a'], x, y, board, res, path, M, N);
            path.pop_back();
            board[x][y] = c;
        }
    }
    void _backtracking(TrieNode* curr, int x, int y, vector<vector<char>>& board, vector<string>& res, string& path, int M, int N) {
        for (auto direction : directions) {
            int _x = x + direction.first;
            int _y = y + direction.second;
            if (_x < 0 || _x >= M || _y < 0 || _y >= N) continue;
            if (board[_x][_y] != '#') {
                char c = board[_x][_y];
                if (curr->children[c - 'a'] != nullptr){
                    board[_x][_y] = '#';
                    path.push_back(c);
                    if (curr->children[c - 'a']->isEnd) {
                        res.push_back(path);
                        curr->children[c - 'a']->isEnd = false;
                    }
                    _backtracking(curr->children[c - 'a'], _x, _y, board, res, path, M, N);
                    path.pop_back();
                    board[_x][_y] = c;
                }
            }
        }
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        for (auto word : words) trie->insert(word);
        int M = board.size();
        int N = board[0].size();
        
        vector<string> res;
        string path;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                trie->backtracking(i, j, board, res, path, M, N);
            }
        }
        return res;
    }
};