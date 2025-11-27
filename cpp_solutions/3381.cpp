class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> mp; // size -> min
        mp[0] = 0;
        long long cur = 0;
        long long res = LLONG_MIN;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int lenRemain = (i + 1) % k;
            cur += nums[i];
            if (mp.count(lenRemain)) {
                res = max(res, cur - mp[lenRemain]);
                mp[lenRemain] = min(mp[lenRemain], cur);
            }
            else {
                mp[lenRemain] = cur;
            }
        }
        return res;
    }
};

