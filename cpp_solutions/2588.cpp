class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long count = 0;
        int prefix = 0;
        unordered_map<int, int> mp;
        mp[prefix]++;
        for (auto& num : nums) {
            prefix ^= num;
            count += mp[prefix];
            mp[prefix]++;
        }
        return count;
    }
};

