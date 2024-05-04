class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        for (auto num : nums) {
            int diff = k - num;
            if (mp[diff] > 0) {
                mp[diff]--;
                count++;
            }
            else {
                mp[num]++;
            }
        }
        return count;
    }
};