class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> toRight(n, INT_MAX / 2);
        vector<int> toLeft(n, INT_MAX / 2);
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'L') continue;
            if (dominoes[i] == 'R') toRight[i] = 0;
            else {
                if (i > 0) toRight[i] = toRight[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'R') continue;
            if (dominoes[i] == 'L') toLeft[i] = 0;
            else {
                if (i < n - 1) toLeft[i] = toLeft[i + 1] + 1;
            }
        }
        
        string res;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] != '.') res.push_back(dominoes[i]);
            else {
                if (toRight[i] >= INT_MAX / 2 && toLeft[i] >= INT_MAX / 2) res.push_back('.');
                else if (toRight[i] < toLeft[i]) res.push_back('R');
                else if (toRight[i] > toLeft[i]) res.push_back('L');
                else res.push_back('.');
            }
        }
        return res;
    }
};