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