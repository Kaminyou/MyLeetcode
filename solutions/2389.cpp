class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = queries.size();
        vector<int> res(m, 0);
        
        for (int i = 0; i < m; ++i) {
            int query = queries[i];
            int curr = 0;
            int index = 0;
            while (index < n && curr <= query) {
                curr += nums[index];
                index++;
            }
            res[i] = index - 1;
            if (curr <= query) res[i] = index;
        }
        return res;
    }
};