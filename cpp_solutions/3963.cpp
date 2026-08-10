class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        for (int i = 0; i < m; ++i) {
            string sub = "";
            for (int j = 0; j < n; ++j) {
                if (i == 0) sub.push_back('.');
                else {
                    if (j == n - 1) sub.push_back('.');
                    else sub.push_back('#');
                }
            }
            res.push_back(sub);
        }
        return res;
    }
};
