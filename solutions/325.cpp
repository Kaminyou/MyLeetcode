class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // prefixSum
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int diff = nums[i] - k;
            if (mp.find(diff) != mp.end()) res = max(res, i - mp[diff]);
            if (mp.find(nums[i]) == mp.end()) mp[nums[i]] = i;
        }
        return res;
    }
};
