class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int current = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxLength = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) current += 1;
            else current -= 1;
            if (mp.count(current)) maxLength = max(maxLength, i - mp[current]);
            else mp[current] = i;
        }
        return maxLength;
    }
};
