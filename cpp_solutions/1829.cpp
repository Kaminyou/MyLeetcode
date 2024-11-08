class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxValue = (1 << maximumBit) - 1;
        int xorAll = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) xorAll ^= nums[i];

        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            res[n - i - 1] = maxValue ^ xorAll;
            xorAll ^= nums[i];
        }
        return res;
    }
};
// max value = 1 << maximumBit - 1
// Y xor X = max => X = max xor Y
