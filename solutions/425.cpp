class Solution {
public:
    int N;
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp; 
    void backtracking(vector<string>& words, vector<string>& path, int currSize) {
        if (currSize == N) {
            res.push_back(path);
            return;
        }
        if (path.size() == 0) {
            for (auto& word : words) {
                path.push_back(word);
                backtracking(words, path, currSize + 1);
                path.pop_back();
            }
        }
        else {
            string prefix = "";
            for (int i = 0; i < currSize; i++) {
                prefix.push_back(path[i][currSize]);
            }
            for (auto& word : mp[prefix]) {
                path.push_back(word);
                backtracking(words, path, currSize + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        N = words[0].size();
        for (auto& word : words) {
            for (int i = 1; i < N; ++i) {
                string temp = word.substr(0, i);
                mp[temp].push_back(word);
            }
        }
        vector<string> path;
        backtracking(words, path, 0);
        return res;
    }
};