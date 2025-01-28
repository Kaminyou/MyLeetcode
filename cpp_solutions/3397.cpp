class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int current = INT_MIN;
        for (auto& num : nums) {
            int minVal = num - k;
            int maxVal = num + k;
            if (current + 1 <= maxVal) {
                res++;
                current = max(current + 1, minVal);
            }
        }
        return res;
    }
};
