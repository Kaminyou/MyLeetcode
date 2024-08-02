class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int oneCnt = 0;
        for (auto& num : nums) {
            if (num)
                oneCnt += 1;
        }
        if (oneCnt == 0) return 0;

        int currentOneCnt = 0;
        for (int i = 0; i < oneCnt - 1; ++i) {
            if (nums[i])
                currentOneCnt += 1;
        }
        int res = INT_MAX;
        for (int i = oneCnt - 1; i < n + oneCnt - 1; ++i) {
            if (nums[i % n])
                currentOneCnt += 1;
            res = min(res, oneCnt - currentOneCnt);
            if (nums[(i - oneCnt + 1) % n])
                currentOneCnt -= 1;
        }
        return res;
    }
};
