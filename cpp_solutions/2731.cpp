class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> newLocation(n, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                newLocation[i] = static_cast<long long>(nums[i]) - d;
            }
            else {
                newLocation[i] = static_cast<long long>(nums[i]) + d;
            }
        }

        long long res = 0;
        long long mod = 1e9 + 7;
        sort(newLocation.begin(), newLocation.end());
        for (int i = 0; i < n - 1; ++i) {
            long long left = 1 + i;
            long long right = n - left;
            long long distance = newLocation[i + 1] - newLocation[i];
            distance %= mod;
            distance *= left;
            distance %= mod;
            distance *= right;
            distance %= mod;
            res += distance;
            res %= mod;
        }
        return res;
    }
};
