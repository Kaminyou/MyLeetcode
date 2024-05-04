class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        vector<int> numsCopy = nums;
        sort(numsCopy.begin(), numsCopy.end());
        
        int slow = 0;
        for (int fast = 0; fast < n; ++fast) {
            while (numsCopy[slow] < numsCopy[fast]) slow++;
            mp[numsCopy[fast]] = slow;
        }
        
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            res[i] = mp[nums[i]];
        }
        return res;
    }
};