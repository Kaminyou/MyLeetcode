class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        int element = -101;
        while (fast < n) {
            if (nums[fast] != element) {
                nums[slow] = nums[fast];
                element = nums[fast];
                slow++;
                fast++;
            }
            else {
                fast++;
            }
        }
        return slow;
    }
};