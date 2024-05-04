class Solution {
public:
    vector<string> res;
    void backtracking(int index, int count, string& s, string& path) {
        if (count == 4) {
            if (index == s.size()) {
                path.pop_back();
                res.push_back(path);
                path.push_back('.');
            }
            else return;
        }
        int cum = 0;
        for (int i = 0; i < 3; ++i) {
            if (index + i >= s.size()) break; 
            cum *= 10;
            cum += s[index + i] - '0';
            if (cum > 255) break;
            if (i > 0 && cum == 0) break;
            if (s[index] == '0' && cum > 0) break;
            for (int j = 0; j <= i; ++j) {
                path.push_back(s[index + j]);
            }
            path.push_back('.');
            backtracking(index + i + 1, count + 1, s, path);
            path.pop_back();
            for (int j = 0; j <= i; ++j) {
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string path;
        backtracking(0, 0, s, path);
        return res;
    }
};