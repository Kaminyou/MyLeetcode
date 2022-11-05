class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        int left = 0; // valid interval [left, n - 1]
        sort(nums.begin(), nums.end());
        vector<int> mods;
        
        unordered_map<int, int> counts;
        for (auto& num : nums) {
            int mod = num % space;
            mods.push_back(mod);
            counts[mod]++;
        }
        
        int res = INT_MAX;
        int clean = 0;
        for (int i = 0; i < n; ++i) {
            while (nums[left] < nums[i]) {
                counts[mods[left]]--;
                left++;
            }
            int currentClean = counts[mods[i]];
            if (currentClean > clean) {
                clean = currentClean;
                res = nums[i];
            }
        }
        return res;
    }
};
