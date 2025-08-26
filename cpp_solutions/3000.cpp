class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0;
        int maxArea = 0;
        for (auto& dimension : dimensions) {
            int x = dimension[0];
            int y = dimension[1];
            int diag = x * x + y * y;
            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = x * y;
            }
            else if (diag == maxDiag) {
                if (x * y > maxArea) {
                    maxArea = x * y;
                }
            }
        }
        return maxArea;
    }
};
