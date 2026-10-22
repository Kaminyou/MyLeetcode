class Solution {
public:
    bool isSortable(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        if (nums[0] > nums[n - 1]) flag = false;
        int curr = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < curr) {
                if (flag) return false;
                flag = true;
            }
            curr = nums[i];
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        bool rev = false;
        if (!isSortable(nums)) {
            reverse(nums.begin(), nums.end());
            rev = true;
        }
        if (!isSortable(nums)) return -1;
        int index = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                index = i;
                break;
            }
        }
        if (rev) {
            return min(index + rev, n - index + rev);
        }
        return min(index, n - index + 2);
    }
};

