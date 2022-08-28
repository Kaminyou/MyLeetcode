class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int base = m - 1;
        int collectionSize = m + n - 1;
        vector<vector<int>> collection(collectionSize);
        vector<int> collectionIdx(collectionSize, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = j - i + base;
                collection[index].push_back(mat[i][j]);
            }
        }
        for (int i = 0; i < collectionSize; ++i) {
            sort(collection[i].begin(), collection[i].end());
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = j - i + base;
                int num = collection[index][collectionIdx[index]];
                mat[i][j] = num;
                collectionIdx[index]++;
            }
        }
        return mat;
    }
};