class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for (auto& num : nums) {
            res += mp[num];
            mp[num]++;
        }
        return res;
    }
};