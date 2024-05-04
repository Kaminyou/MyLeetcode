class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int posLen = 1;
        int negLen = 1;
        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            int currPos = 1;
            int currNeg = 1;
            if (nums[i] > nums[i - 1]) {
                currPos = max(posLen, negLen + 1);
                currNeg = negLen;
            }
            else if (nums[i] < nums[i - 1]) {
                currPos = posLen;
                currNeg = max(negLen, posLen + 1);
            }
            else {
                currPos = posLen;
                currNeg = negLen;
            }
            posLen = currPos;
            negLen = currNeg;
            maxLen = max({maxLen, posLen, negLen});
        }
        return maxLen;
    }
};

// v2
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         vector<int> newNums;
//         int index = 0;
//         while (index < nums.size()) {
//             int start = nums[index];
//             while (index + 1 < nums.size() && nums[index + 1] == start) index++;
//             newNums.push_back(nums[index]);
//             index++;
//         }
//         nums = newNums;
//         if (nums.size() == 1) return 1;
//         int positive = 0;
//         int negative = 0;
//         int start = nums[0];
//         for (int i = 1; i < nums.size() - 1; ++i) {
//             if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) positive++;
//             if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) negative++;
//         }
//         return positive + negative + 2;
//     }
// };