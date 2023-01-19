class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        int sum = 0;
        mp[0]++;
        for (auto& num : nums) {
            sum += num;
            int mod = ((sum % k) + k) % k;
            res += mp[mod];
            mp[mod]++;
        }
        return res;
    }
};
