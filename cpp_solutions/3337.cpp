class Solution {
public:
    long long mod = 1e9 + 7;
    vector<vector<long long>> toMatrix(vector<int>& nums) {
        vector<vector<long long>> matrix(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                matrix[i][(i + j + 1) % 26]++;
            }
        }
        return matrix;
    }
    vector<vector<long long>> multiplyMatrix(vector<vector<long long>>& matrix1, vector<vector<long long>>& matrix2) {
        int m = matrix1.size();
        int n = matrix1[0].size();
        int o = matrix2[0].size();
        vector<vector<long long>> matrix(m, vector<long long>(o, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < o; ++j) {
                for (int k = 0; k < n; ++k) {
                    matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                    matrix[i][j] %= mod;
                }
            }
        }
        return matrix;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> numsMatrix(26, vector<long long>(1, 0));
        for (int i = 0; i < 26; ++i) {
            numsMatrix[i][0] = 1;
        }
        vector<vector<long long>> matrix = toMatrix(nums);
        vector<bool> bits(32, 0);
        int index = 0;
        int maxBit = 0;
        while (t) {
            if (t & 1) {
                bits[index] = 1;
                maxBit = index;
            }
            t >>= 1;
            index++;
        }
        vector<vector<vector<long long>>> hashMatrix(32);
        vector<vector<long long>> curMatrix = matrix;
        for (int i = 0; i < maxBit + 1; ++i) {
            hashMatrix[i] = curMatrix;
            curMatrix = multiplyMatrix(curMatrix, curMatrix);
        }
        for (int i = 0; i < maxBit + 1; ++i) {
            if (bits[i]) {
                numsMatrix = multiplyMatrix(hashMatrix[i], numsMatrix);
            }
        }
        long long res = 0;
        for (auto& c : s) {
            res += numsMatrix[c - 'a'][0];
            res %= mod;
        }
        return res;
    }
};

