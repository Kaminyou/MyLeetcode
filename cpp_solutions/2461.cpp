class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0;
        long long sum = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        int unique = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            mp[nums[i]]++;
            if (mp[nums[i]] == 1) unique++;
        }
        
        if (unique == k) res = max(res, sum);
        
        for (int i = k; i < n; ++i) {
            sum += nums[i];
            mp[nums[i]]++;
            if (mp[nums[i]] == 1) unique++;
            
            sum -= nums[i - k];
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] == 0) unique--;
            
            if (unique == k) res = max(res, sum);
        }
        return res;
    }
};