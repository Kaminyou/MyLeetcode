class Solution {
public:
    static bool compare(const pair<string, int>& v1, const pair<string, int>& v2) {
        if (v1.first == v2.first) return v1.second < v2.second;
        return v1.first < v2.first;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int stringLength = nums[0].size();
        unordered_map<int, vector<pair<string, int>>> precomputedMp;
        
        for (int i = 1; i <= stringLength; ++i) {
            vector<pair<string, int>> v;
            for (int j = 0; j < nums.size(); ++j) {
                v.push_back(make_pair(nums[j].substr(stringLength - i, i), j));
            }
            sort(v.begin(), v.end(), compare);
            precomputedMp[i] = v;
        }
        
        int queriesSize = queries.size();
        vector<int> res(queriesSize, 0);
        for (int i = 0; i < queriesSize; ++i) {
            auto& query = queries[i];
            int ans = precomputedMp[query[1]][query[0] - 1].second;
            res[i] = ans;
        }
        return res;
    }
};