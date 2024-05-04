class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int current = nums[i];
            if (current == k) res++;
            for (int j = i + 1; j < n; ++j) {
                current = current * (nums[j] / __gcd(current, nums[j]));
                if (current == k) res++;
                if (current > k) break;
            }
        }
        return res;
    }
};