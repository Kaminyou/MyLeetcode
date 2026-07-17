class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<long long> gcd(m + 1, 0);
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            mp[num]++;
        }
        for (int num = m; num >= 1; --num) {
            long long cnt = 0;
            for (int cur = num; cur <= m; cur += num) {
                cnt += mp[cur];
            }
            gcd[num] = cnt * (cnt - 1) / 2;
            for (int cur = num * 2; cur <= m; cur += num) {
                gcd[num] -= gcd[cur];
            }
        }
        vector<long long> gcdPrefix(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            gcdPrefix[i] = gcdPrefix[i - 1] + gcd[i];
        }
        vector<int> res;
        for (auto& q : queries) {
            res.push_back(lower_bound(gcdPrefix.begin(), gcdPrefix.end(), q + 1) - gcdPrefix.begin());
        }
        return res;
    }
};

