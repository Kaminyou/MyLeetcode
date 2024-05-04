class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int countOnes = 0;
        for (auto num : nums) {
            if (num == 1) countOnes++;
        }
        if (countOnes > 0) return n - countOnes;
        
        int minLength = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    minLength = min(minLength, j - i + 1);
                    break;
                }
            }
        }
        if (minLength == INT_MAX) return -1;
        return minLength - 1 + n - 1;
    }
};