class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 2; ++i) {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];
            if ((a + c) * 2 == b) res++;
        }
        return res;
    }
};
