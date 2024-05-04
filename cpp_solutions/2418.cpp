class Solution {
public:
    static bool compare(const pair<int, string>& p1, const pair<int, string>& p2) {
        if (p1.first != p2.first) return p1.first > p2.first;
        return p1.second > p2.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;
        int n = names.size();
        for (int i = 0; i < n; ++i) {
            v.push_back(make_pair(heights[i], names[i]));
        }
        sort(v.begin(), v.end(), compare);
        vector<string> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(v[i].second);
        }
        return res;
    }
};