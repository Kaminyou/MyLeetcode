class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        int res = 0;
        while (index < n) {
            if (nums[index] == 1) {
                int start = index;
                while (index + 1 < n && nums[index + 1] == 1) index++;
                res = max(res, index - start + 1);
            }
            index++;
        }
        return res;
    }
};