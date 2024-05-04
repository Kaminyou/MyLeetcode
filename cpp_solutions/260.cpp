class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long bitmask = 0;
        for (auto& num : nums) bitmask ^= num;
        
        // lsb
        long long diff = bitmask & (-bitmask);
        long long x = 0;
        for (auto& num : nums) {
            if (num & diff) x ^= num;
        }
        return {static_cast<int>(x), static_cast<int>(bitmask ^ x)};
    }
};