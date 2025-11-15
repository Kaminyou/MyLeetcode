class Solution {
public:
    vector<int> computeRightOnes(string& s) {
        int n = s.size();
        vector<int> rightOnes(n, 0);
        for (int i = n - 2; i >= 0; --i) {
            if (s[i + 1] == '1') {
                rightOnes[i] = rightOnes[i + 1] + 1;
            }
        }
        return rightOnes;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> rightOnes = computeRightOnes(s);
        int res = 0;
        for (int m = 1; m <= 200; ++m) {
            int right = 0;
            int countZero = 0;
            for (int left = 0; left < n; ++left) {
                while (right < n && countZero < m) {
                    if (s[right] == '0') {
                        countZero++;
                    }
                    right++;
                }
                if (countZero < m) break;
                int countOne = (right - left) - countZero;
                if (rightOnes[right - 1] + countOne >= m * m) {
                    int extra = rightOnes[right - 1] - max(0, m * m - countOne);
                    res += extra + 1;
                }
                countZero -= (s[left] == '0');
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                res += rightOnes[i] + 1;
            }
        }
        return res;
    }
};
