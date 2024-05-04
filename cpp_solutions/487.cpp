class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int nonFlip = 0;
        int oneFlip = 0;
        int res = 0;
        for (auto num : nums) {
            if (num == 0) {
                oneFlip = nonFlip + 1;
                nonFlip = 0;
            }
            else {
                nonFlip++;
                oneFlip++;
            }
            res = max({res, oneFlip, nonFlip});
        }
        return res;
    }
};