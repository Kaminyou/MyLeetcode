class Solution {
public:
    bool check(long long t, int n, vector<int>& batteries) {
        long long sum = 0;
        for (auto& battery : batteries) {
            sum += min(t, (long long)battery);
        }
        return (long long)t * (long long)n <= sum;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 0;
        long long right = LLONG_MAX / n;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (!check(mid, n, batteries)) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};