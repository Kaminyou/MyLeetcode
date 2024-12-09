class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        map<int, int> mp;
        int start = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (((nums[i - 1] & 1) ^ (nums[i] & 1)) == 0) {
                mp[start] = i - 1;
                start = i;
            }
        }
        mp[start] = n - 1;

        int m = queries.size();
        vector<bool> res(m, false);
        for (int j = 0; j < m; ++j) {
            int a = queries[j][0];
            int b = queries[j][1];

            auto t = mp.upper_bound(a);
            t--;
            int end = t->second;
            if (end >= b) res[j] = true;
        }
        return res;
    }
};

