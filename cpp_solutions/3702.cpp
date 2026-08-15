class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int v = 0;
        int cntZero = 0;
        for (auto& num : nums) {
            v ^= num;
            if (num == 0) cntZero++;
        }
        if (v != 0) return n;
        if (cntZero != n) return n - 1;
        return 0;
    }
};

