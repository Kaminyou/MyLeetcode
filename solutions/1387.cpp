class Solution {
public:
    unordered_map<int, int> mp;
    int dp(int x) {
        if (x == 1) return 0;
        if (mp.find(x) != mp.end()) return mp[x];
        if (x & 1) return mp[x] = dp(x * 3 + 1) + 1;
        else return mp[x] = dp(x / 2) + 1;
    }
    static bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.second != p2.second) return p1.second < p2.second;
        return p1.first < p2.first;
    } 
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;
        for (int i = lo; i <= hi; ++i) {
            v.push_back(make_pair(i, 0));
        }
        for (int i = 0; i < v.size(); ++i) {
            v[i].second = dp(v[i].first);
        }
        sort(v.begin(), v.end(), compare);
        return v[k - 1].first;
    }
};