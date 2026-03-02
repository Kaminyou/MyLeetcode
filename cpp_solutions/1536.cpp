class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zerosCnt(n, 0);
        for (int i = 0; i < n; ++i) {
            int index = n - 1;
            while (index >= 0 && grid[i][index] != 1) index--;
            zerosCnt[i] = n - 1 - index;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int target = n - 1 - i;
            if (zerosCnt[i] < target) {
                int j = i;
                while (j < n && zerosCnt[j] < target) j++;
                if (j == n) return -1;
                while (j != i) {
                    swap(zerosCnt[j - 1], zerosCnt[j]);
                    j--;
                    res++;
                }
            }
        }
        return res;
    }
};
