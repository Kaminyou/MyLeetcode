class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto stone : stones) mp[stone] = unordered_set<int>();
        mp[0].insert(0);
        
        for (auto stone : stones) {
            for (auto step : mp[stone]) {
                for (int i = step - 1; i <= step + 1; ++i) {
                    if (i <= 0) continue;
                    if (mp.find(stone + i) != mp.end()) {
                        mp[stone + i].insert(i);
                    }
                }
            }    
        }
        return mp[stones.back()].size() > 0;
    }
};