class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        vector<long long> prefix(n, 0);
        for (int i = 0; i < n; ++i) {
            sum += chalk[i];
            prefix[i] = chalk[i];
            if (i >= 1) prefix[i] += prefix[i - 1];
        }
        long long K = k;
        K %= sum;
        auto it = upper_bound(prefix.begin(), prefix.end(), K);
        int index = it - prefix.begin();
        return index;
    }
};
