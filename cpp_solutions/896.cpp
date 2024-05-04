class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool incFlag = true;
        bool decFlag = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) incFlag = false;
            if (nums[i] > nums[i - 1]) decFlag = false;
        }
        return incFlag || decFlag;
    }
};