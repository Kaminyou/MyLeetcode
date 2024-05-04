class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int maxWithoutSquare = nums[0];
        int maxWithSquare = nums[0] * nums[0];
        int res = maxWithSquare;
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            maxWithSquare = max({maxWithSquare + num, maxWithoutSquare + num * num, num * num});
            maxWithoutSquare = max(maxWithoutSquare + num, num);
            res = max(res, maxWithSquare);
        }
        return res;
    }
};