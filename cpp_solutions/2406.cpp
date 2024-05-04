class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for (auto& interval : intervals) {
            mp[interval[0]]++;
            mp[interval[1] + 1]--;
        }
        int res = 0;
        int current = 0;
        for (auto element : mp) {
            current += element.second;
            res = max(res, current);
        }
        return res;
    }
};