class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (auto& num : nums) counts[num]++;
        vector<pair<int, int>> v;
        for (auto& element : counts) v.push_back({element.first, element.second});
        sort(v.begin(), v.end());
        int n = v.size();
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (v[i + 1].first - v[i].first == 1) res = max(res, v[i + 1].second + v[i].second);
        }
        return res;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (auto& num : nums) cnts[num]++;
        int res = 0;
        for (auto& [num, cnt] : cnts) {
            if (!cnts.count(num + 1)) continue;
            res = max(res, cnts[num] + cnts[num + 1]);
        }
        return res;
    }
};
