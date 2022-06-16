class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        mp[sum]++;
        for (auto& num : nums) {
            sum += num;
            if (mp.find(sum - k) != mp.end()) res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};