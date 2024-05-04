class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        
        // count views
        int maxView = 0;
        unordered_map<string, int> mp;
        unordered_map<string, pair<string, int>> creator2bestView;
        for (int i = 0; i < n; ++i) {
            mp[creators[i]] += views[i];
            maxView = max(maxView, mp[creators[i]]);
            
            if (creator2bestView.find(creators[i]) == creator2bestView.end()) {
                creator2bestView[creators[i]] = {ids[i], views[i]};
            }
            else {
                if (views[i] > creator2bestView[creators[i]].second) {
                    creator2bestView[creators[i]] = {ids[i], views[i]};
                }
                else if (views[i] == creator2bestView[creators[i]].second) {
                    if (ids[i] < creator2bestView[creators[i]].first) {
                        creator2bestView[creators[i]] = {ids[i], views[i]};
                    }
                }
            }
        }
        
        vector<vector<string>> res;
        // find their id with the most view
        for (auto& [creator, cnt] : mp) {
            if (cnt == maxView) {
                res.push_back({creator, creator2bestView[creator].first});
            }
        }
        return res;
    }
};