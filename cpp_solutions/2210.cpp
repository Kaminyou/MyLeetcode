class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> nums2;
        int prev = -1;
        for (auto& num : nums) {
            if (num != prev) {
                nums2.push_back(num);
            }
            prev = num;
        }
        int res = 0;
        int n = nums2.size();
        for (int i = 1; i < n - 1; ++i) {
            if (nums2[i] > nums2[i - 1] && nums2[i] > nums2[i + 1]) res++;
            if (nums2[i] < nums2[i - 1] && nums2[i] < nums2[i + 1]) res++;
        }
        return res;
    }
};
