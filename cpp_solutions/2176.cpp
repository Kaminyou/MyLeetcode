class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int count = 0;
        for (auto& [num, indices] : mp) {
            int n = indices.size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if ((indices[i] * indices[j]) % k == 0) count++;
                }
            }
        }
        return count;
    }
};