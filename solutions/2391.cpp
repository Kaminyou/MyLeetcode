class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int metalLast = 0;
        int paperLast = 0;
        int glassLast = 0;
        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + travel[i - 1];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += garbage[i].size();
            for (auto c : garbage[i]) {
                if (c == 'M') {
                    metalLast = i;
                }
                else if (c == 'P') {
                    paperLast = i;
                }
                else {
                    glassLast = i;
                }
            }
        }
        res += prefixSum[metalLast];
        res += prefixSum[paperLast];
        res += prefixSum[glassLast];
        return res;
    }
};