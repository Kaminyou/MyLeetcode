class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool valid = true;
                int w1 = words[i].size();
                int w2 = words[j].size();
                if (w1 > w2) continue;
                for (int k = 0; k < w1; ++k) {
                    if (words[i][k] != words[j][k]) {
                        valid = false;
                    }
                    if (words[i][w1 - k - 1] != words[j][w2 - k - 1]) {
                        valid = false;
                    }
                    if (!valid) break;
                }
                if (valid) {
                    res++;
                }
            }
        }
        return res;
    }
};
