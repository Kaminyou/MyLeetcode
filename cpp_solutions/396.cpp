class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int init = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            init += i * nums[i];
            sum += nums[i];
        }
        int res = INT_MIN;
        res = max(res, init);
        for (int i = nums.size() - 1; i > 0; --i) {
            init += sum;
            init -= nums[i] * nums.size();
            res = max(res, init);
        }
        return res;
    }
};