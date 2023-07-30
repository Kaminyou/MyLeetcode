class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int first = -1;
        int last = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) first = i;
            if (nums[i] == n) last = i;
        }
        if (last > first) return first + ((n - 1) - last);
        return first + ((n - 1) - last) - 1;
    }
};