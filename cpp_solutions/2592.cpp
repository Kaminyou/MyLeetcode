class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        int greatness = 0;
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (idx < n && nums[idx] <= nums[i]) idx++;
            if (idx == n) break;
            idx++;
            greatness++;
        }

        return greatness;
    }
};
