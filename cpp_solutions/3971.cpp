class Solution {
public:
    long long count(vector<int>& value, vector<int>& decay, int threshold) {
        int n = value.size();
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            int v = value[i];
            int d = decay[i];
            if (v >= threshold) {
                int cnt = (v - threshold) / d + 1;
                total += cnt;
            }
        }
        return total;
    }
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int left = 0;
        int right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (count(value, decay, mid) < (long long)m) right = mid;
            else left = mid + 1;
        }
        int threshold = left;
        int remaining = m;
        int n = value.size();
        long long sum = 0;
        long long mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int v = value[i];
            if (v < threshold) continue;
            int d = decay[i];
            int cnt = (v - threshold) / d + 1;
            long long vv = v - d * (cnt - 1);
            remaining -= cnt;
            sum += (v + vv) * cnt / 2;
        }
        if (remaining && threshold > 0) sum += (long long)remaining * (threshold - 1);
        return sum % mod;
    }
};
