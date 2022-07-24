class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m - 1;
        int col = 0;
        
        while (row >= 0 && row < m && col >= 0 && col < n) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) col++;
            else row--;
        }
        
        return false;
    }
};