class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) {
                res += 1;
                for (int j = i; j < i + 3; ++j) {
                    nums[j] = nums[j] ^ 1;
                }
            }
        }
        for (int i = n - 2; i < n; ++i) {
            if (nums[i] != 1) return -1;
        }
        return res;
    }
};
