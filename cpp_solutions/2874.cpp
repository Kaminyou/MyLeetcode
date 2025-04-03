class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        long long maxVal = INT_MIN;
        long long diff = 0;
        int n = nums.size();
        vector<long long> maxElementBackward(n, 0);
        maxElementBackward[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxElementBackward[i] = max((long long)nums[i], maxElementBackward[i + 1]);
        }
        
        for (int i = 0; i < n; ++i) {
            diff = max(diff, maxVal - nums[i]);
            maxVal = max(maxVal, (long long)nums[i]);
            if (i >= 1 && i < n - 1) {
                long long right = maxElementBackward[i + 1];
                long long curr = diff * right;
                res = max(res, curr);
            }
        }
        return res;
    }
};
