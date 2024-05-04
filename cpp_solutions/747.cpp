class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largestIdx = -1;
        int largestNum = -1;
        int secondNum = -1;
        for (int i = 0; i < nums.size(); ++i) {
            auto& num = nums[i];
            if (num > largestNum) {
                secondNum = largestNum;
                largestNum = num;
                largestIdx = i;
            }
            else if (num > secondNum) {
                secondNum = num;
            }
        }
        if (largestNum >= secondNum * 2) return largestIdx;
        return -1;
    }
};