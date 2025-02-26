class Solution {
public:
    int kadane(vector<int>& nums) {
        int res = INT_MIN;
        int current = 0;
        for (auto& num : nums) {
            current += num;
            if (current < 0) current = max(0, num);
            res = max(res, current);
        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int res = INT_MIN;
        res = max(res, kadane(nums));
        for (auto& num : nums) {
            num = -num;
        }
        res = max(res, kadane(nums));
        return res;
    }
};
