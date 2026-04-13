class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) res = min(res, abs(i - start));
        }
        return res;
    }
};
