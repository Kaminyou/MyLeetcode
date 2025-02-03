class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;
        int cnt = 0;

        // increase
        int curr = INT_MIN;
        for (auto& num : nums) {
            if (num > curr) {
                cnt++;
                res = max(res, cnt);
            }
            else {
                cnt = 1;
            }
            curr = num;
        }

        // decrease
        curr = INT_MAX;
        cnt = 0;
        for (auto& num : nums) {
            if (num < curr) {
                cnt++;
                res = max(res, cnt);
            }
            else {
                cnt = 1;
            }
            curr = num;
        }
        return res;
    }
};
