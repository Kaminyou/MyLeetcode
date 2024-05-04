class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for (auto& num : nums) x ^= num;
        x ^= k;
        return __builtin_popcount(x);
    }
};
