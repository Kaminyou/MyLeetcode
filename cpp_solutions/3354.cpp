class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        int res = 0;
        for (auto& num : nums) {
            rightSum += num;
        }
        for (auto& num : nums) {
            rightSum -= num;
            if (num == 0) {
                if (rightSum == leftSum) res += 2;
                if (abs(rightSum - leftSum) == 1) res += 1;
            }
            leftSum += num;
        }
        return res;
    }
};
