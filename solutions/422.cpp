class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        bool flag = true;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            int m = words[i].size();
            if (m > n) return false;
            for (int j = 0; j < m; ++j) {
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};