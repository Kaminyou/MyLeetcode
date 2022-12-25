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

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        vector<int> res(m, 0);
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<pair<int, int>> queriesWithIdx(m, {0, 0});
        for (int i = 0; i < m; ++i) {
            queriesWithIdx[i].first = queries[i];
            queriesWithIdx[i].second = i;
        }
        sort(queriesWithIdx.begin(), queriesWithIdx.end());

        int index = 0;
        int sum = 0;
        for (auto& [query, idx] : queriesWithIdx) {
            while (index < n && sum + nums[index] <= query) {
                sum += nums[index];
                index++;
            }
            res[idx] = index;
        }
        return res;
    }
};