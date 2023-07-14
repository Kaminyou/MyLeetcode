class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int res = 1;
        for (auto num : arr) {
            int prev = num - difference;
            int current = 1;
            if (mp.count(prev)) {
                current += mp[prev];
            }
            mp[num] = current;
            res = max(res, current);
        }
        return res;
    }
};