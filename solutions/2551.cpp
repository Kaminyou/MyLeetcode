class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) return 0;
        int n = weights.size();
        vector<long long> cuts(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            cuts[i] = (long long)weights[i] + (long long)weights[i + 1];
        }
        sort(cuts.begin(), cuts.end());
        long long maxValue = 0;
        long long minValue = 0;
        int selections = k - 1;
        for (int i = 0; i < selections; ++i) {
            minValue += cuts[i];
        }
        for (int i = n - 2; i >= n - 1 - selections; --i) {
            maxValue += cuts[i];
        }
        return maxValue - minValue;
    }
};
