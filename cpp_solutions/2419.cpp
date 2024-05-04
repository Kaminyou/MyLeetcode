class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = -1;
        int maxLength = 0;
        int index = 0;
        int n = nums.size();

        while (index < n) {
            int num = nums[index];
            int start = index;
            while (index + 1 < n && nums[index + 1] == num) index++;
            if (num > maxVal) {
                maxVal = num;
                maxLength = index - start + 1;
            }
            else if (num == maxVal) {
                maxLength = max(maxLength, index - start + 1);
            }
            index++;
        }
        return maxLength;
    }
};