class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<bool> hash(1000, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || i == k) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num < 100) continue;
                    if (num & 1) continue;
                    if (!hash[num]) {
                        res++;
                        hash[num] = true;
                    }
                }
            }
        }
        return res;
    }
};
