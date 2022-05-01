typedef pair<int, string> P;
class Solution {
public:
    static bool compare(const P& p1, const P& p2) {
        if (p1.first != p2.first) return p1.first > p2.first;
        int minLen = min(p1.second.size(), p2.second.size());
        for (int i = 0; i < minLen; i++) {
            if (p1.second[i] != p2.second[i]) return p1.second[i] < p2.second[i];
        }
        return p1.second.size() < p2.second.size();
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> st;
        for (auto word : words) st[word]++;
        vector<P> v; // freq, string
        for (auto element : st) v.push_back(make_pair(element.second, element.first));
        sort(v.begin(), v.end(), compare);
        
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};