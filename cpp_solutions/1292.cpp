class Solution {
public:
    int valid(int m, int n, int* prefixSum, int k, int threshold) {
        int minSum = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + k > m) break;
                if (j + k > n) break;
                int sum = prefixSum[(i + k) * (n + 1) + j + k] - prefixSum[i * (n + 1) + j + k] - prefixSum[(i + k) * (n + 1) + j] + prefixSum[i * (n + 1) + j];
                minSum = min(minSum, sum);
            }
        }
        return minSum > threshold;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        int prefixSum[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) prefixSum[i][0] = 0;
        for (int j = 0; j <= n; ++j) prefixSum[0][j] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] + mat[i][j] - prefixSum[i][j];
            }
        }
        
        int left = 0;
        int right = min(m, n) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(m, n, (int *)prefixSum, mid, threshold)) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};

