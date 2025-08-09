class Solution {
public:
    int getDPMost(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int tops[1001];
        int temps[1001];
        for (int i = 0; i < n; ++i) tops[i] = 0;
        for (int i = n - 2; i >= 0; --i) {
            // [i+1...n-1]            
            for (int j = 0; j < n; ++j) temps[j] = 0;
            for (int j = i + 1; j <= n - 1; ++j) {
                if (j - 1 >= 0) temps[j] = max(temps[j], tops[j - 1] + fruits[i][j]);
                temps[j] = max(temps[j], tops[j] + fruits[i][j]);
                if (j + 1 < n) temps[j] = max(temps[j], tops[j + 1] + fruits[i][j]);
            }
            for (int j = 0; j < n; ++j) tops[j] = temps[j];
        }
        return tops[n - 1];
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res = 0;
        int n = fruits.size();
        for (int i = 0; i < n; ++i) {
            res += fruits[i][i];
            fruits[i][i] = 0;
        }

        res += getDPMost(fruits);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(fruits[i][j], fruits[j][i]);
            }
        }
        res += getDPMost(fruits);
        return res;
    }
};
