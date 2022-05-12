class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int position = 0;
            for (int i = 0; i < n; i++) {
                position += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (position >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};