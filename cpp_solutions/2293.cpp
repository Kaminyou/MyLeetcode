class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> temp;
            int n = nums.size();
            bool minFlag = true;
            for (int i = 0; i < n; i += 2) {
                if (minFlag) {
                    temp.push_back(min(nums[i], nums[i + 1]));
                }
                else {
                    temp.push_back(max(nums[i], nums[i + 1]));
                }
                minFlag = !minFlag;
                nums = temp;
            }
        }
        return nums[0];
    }
};