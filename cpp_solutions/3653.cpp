class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod = 1e9 + 7;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];
            for (int index = l; index <= r; index += k) {
                long long now = nums[index];
                now *= v;
                now %= mod;
                nums[index] = now;
            }
        }
        int res = 0;
        for (auto& num : nums) res ^= num;
        return res;
    }
};
