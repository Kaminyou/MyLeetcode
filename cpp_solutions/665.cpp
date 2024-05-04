class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = true;
        int left = -1;
        int right = -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                if (!flag) return false;
                flag = false;
                left = i;
                right = i + 1;
            }
        }
        if (left > 0 && right + 1 < nums.size() && nums[left - 1] > nums[right] && nums[left] > nums[right + 1]) return false;
        return true;
    }
};