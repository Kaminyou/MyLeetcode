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

// v2
typedef pair<int, string> P;
class Compare {
public:
    bool operator() (const P& p1, const P& p2) const {
        if (p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        multiset<P, Compare> mst;
        unordered_map<string, int> mp;
        for (auto& word : words) {
            if (mp.find(word) != mp.end()) {
                const pair<int, string> p = {mp[word], word};
                if (mst.find(p) != mst.end()) {
                    mst.erase(mst.find(p));
                }
            }
            mp[word]++;
            mst.insert({mp[word], word});
            while (mst.size() > k) mst.erase(mst.begin());
        }
        vector<string> res;
        while (!mst.empty()) {
            res.push_back(mst.begin()->second);
            mst.erase(mst.begin());
        }
        reverse(res.begin(), res.end());
        return res;
    }
};