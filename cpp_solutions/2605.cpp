class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int res = INT_MAX;
        for (auto num1 : nums1) {
            for (auto num2 : nums2) {
                res = min(res, num1 * 10 + num2);
                res = min(res, num1 + num2 * 10);
                if (num1 == num2) res = min(res, num1);
            }
        }
        return res;
    }
};