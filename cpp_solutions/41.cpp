class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool oneFlag = false;
        for (auto& num : nums) {
            if (num == 1) {
                oneFlag = true;
                break;
            }
        }
        if (!oneFlag) return 1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }

        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]);
            if (index == n) {
                nums[0] = -1 * abs(nums[0]);
            }
            else {
                nums[index] = -1 * abs(nums[index]);
            }
        }

        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) return i;
        }
        if (nums[0] > 0) return n;
        return n + 1;
    }
};
