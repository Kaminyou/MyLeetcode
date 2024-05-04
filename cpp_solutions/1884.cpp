class Solution {
public:
    int recursive(int k, int n, vector<vector<int>>& memo) {
        if (k == 0) return 0;
        if (k == 1) return n;
        if (n <= 1) return n;
        if (memo[k][n] != INT_MAX) return memo[k][n];
        for (int i = 1; i <= n; ++i) {
            memo[k][n] = min(memo[k][n], 1 + max(recursive(k - 1, i - 1, memo), recursive(k, n - i, memo)));
        }
        return memo[k][n];
    }
    int twoEggDrop(int n) {
        vector<vector<int>> memo(3, vector<int>(n + 1, INT_MAX));
        return recursive(2, n, memo);
    }
};
// MATH SOLUTION
// class Solution {
// public:
//     int twoEggDrop(int n) {
//         int index = 0;
//         while ((1 + index) * index / 2 < n) index++;
//         return index ;
        
//     }
// };