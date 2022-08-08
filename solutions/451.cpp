class Solution {
public:
    static bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        vector<pair<int, int>> counts;
        for (int i = 0; i < 256; ++i) counts.push_back(make_pair(i, 0));
        for (auto c : s) {
            counts[c].second++;
        }
        sort(counts.begin(), counts.end(), compare);
        string res;
        for (int i = 0; i < 256; ++i) {
            if (counts[i].second == 0) continue;
            char c = counts[i].first;
            int count = counts[i].second;
            res += string(count, c);
        }
        return res;
    }
};