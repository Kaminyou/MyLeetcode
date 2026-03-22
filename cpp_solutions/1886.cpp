class Solution {
public:
    void rot(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        int start = 0;
        int end = n - 1;
        while (end > start) {
            for (int i = 0; i < n; ++i) {
                swap(mat[start][i], mat[end][i]);
            }
            start++;
            end--;
        }
    }
    bool isSame(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; ++i) {
            if (isSame(mat, target)) return true;
            rot(mat);
        }
        return false;
    }
};
