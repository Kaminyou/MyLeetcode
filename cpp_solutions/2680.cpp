class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int highestBit = 0;
        for (auto num : nums) {
            int highBit = 0;
            while (num > 0) {
                num /= 2;
                highBit++;
            }
            highestBit = max(highestBit, highBit);
        }
        vector<int> bitCnts(32, 0);
        vector<vector<int>> bits;
        for (auto num : nums) {
            int highBit = 0;
            vector<int> bit(32, 0);
            while (num > 0) {
                bit[highBit] = num & 1;
                num /= 2;
                highBit++;
            }
            if (highBit == highestBit) {
                bits.push_back(bit);
            }
            for (int i = 0; i < 32; ++i) bitCnts[i] += bit[i];
        }
        
        long long maxValue = 0;
        for (auto bit : bits) {
            long long current = 0;
            for (int i = 0; i < 32; ++i) {
                if (bit[i]) {
                    current += 1 << i;
                    bitCnts[i]--;
                }
            }
            current <<= k;
            for (int i = 0; i < 32; ++i) {
                if (bitCnts[i] && (current & (1 << i)) == 0) {
                    
                    current += 1 << i;
                }
            }
            maxValue = max(maxValue, current);
            
            for (int i = 0; i < 32; ++i) {
                if (bit[i]) bitCnts[i]++;
            }
        }
        return maxValue;
    }
};
