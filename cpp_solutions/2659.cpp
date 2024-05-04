class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        long long res = n;
        for (int i = 1; i < n; ++i) {
            if (mp[nums[i - 1]] > mp[nums[i]]) res += (n - i);
        }
        return res;
    }
};
