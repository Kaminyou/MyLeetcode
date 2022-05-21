class Solution {
public:
    int recursive(int k, int n, vector<vector<int>>& memo) {
        if (k == 0) return 0; // no egg
        if (k == 1) return n; // one egg, so is n
        if (n <= 1) return n; // one floor with many egg => 1 || zero floor => 0
        if (memo[k][n] != INT_MAX) return memo[k][n];
        
        // binary search
        // recursive(k - 1, mid - 1, memo) is monotonic increasing
        // recursive(k, n - mid, memo) is monotonic decresing
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (recursive(k - 1, mid - 1, memo) >= recursive(k, n - mid, memo)) right = mid;
            else left = mid + 1;
        }
        
        memo[k][n] = 1 + max(recursive(k - 1, left - 1, memo), recursive(k, n - left, memo));
        return memo[k][n];
        
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k + 1, vector<int>(n + 1, INT_MAX));
        return recursive(k, n, memo);
    }
};