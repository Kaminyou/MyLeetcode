class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> isSored(n - 1, false);

        int res = 0;
        int cnt = 0;

        for (int j = 0; j < m; ++j) {
            bool isEnd = false;
            for (int i = 0; i < n - 1; ++i) {
                if (!isSored[i] && strs[i][j] > strs[i + 1][j]) {
                    res++;
                    break;
                }
                if (i == n - 2) isEnd = true;
            }

            if (isEnd) {
                for (int i = 0; i < n - 1; ++i) {
                    if (strs[i][j] < strs[i + 1][j]) {
                        isSored[i] = true;
                        cnt++;
                    }
                }
            }
            if (cnt == n) break;
        }
        return res;
    }
};

