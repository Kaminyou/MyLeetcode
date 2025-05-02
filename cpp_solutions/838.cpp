class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> ls(n, INT_MAX);
        vector<int> rs(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'L') rs[i] = INT_MAX;
            else if (dominoes[i] == 'R') rs[i] = 0;
            else if (i >= 1 && rs[i - 1] != INT_MAX) rs[i] = rs[i - 1] + 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'R') ls[i] = INT_MAX;
            else if (dominoes[i] == 'L') ls[i] = 0;
            else if (i < n - 1 && ls[i + 1] != INT_MAX) ls[i] = ls[i + 1] + 1;
        }
        string res = dominoes;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == '.') {
                if (rs[i] < ls[i]) res[i] = 'R';
                else if (rs[i] > ls[i]) res[i] = 'L';
                else res[i] = '.';
            }
        }
        return res;
    }
};
