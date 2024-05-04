class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> disabled;
        int n = fronts.size();
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) disabled.insert(fronts[i]);
        }
        
        int res = 3000;
        for (int i = 0; i < n; ++i) {
            if (disabled.find(fronts[i]) == disabled.end()) res = min(res, fronts[i]);
            if (disabled.find(backs[i]) == disabled.end()) res = min(res, backs[i]);
        }
        if (res != 3000) return res;
        return 0;
    }
};
