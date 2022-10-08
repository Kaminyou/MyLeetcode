class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int res = 0;
        for (int j = 0; j < n; ++j) {
            int current = 0;
            for (int i = 0; i < m; ++i) {
                if (strs[i][j] - 'a' < current) {
                    res++;
                    break;
                }
                current = max(current, strs[i][j] - 'a');
            }
        }
        return res;
    }
};