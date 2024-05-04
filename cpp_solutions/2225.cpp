class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);
        set<int> players;
        unordered_map<int, int> lostTime;
        for (auto& match : matches) {
            players.insert(match[0]);
            players.insert(match[1]);
            lostTime[match[1]]++;
        }
        
        for (auto& player : players) {
            if (lostTime[player] == 0) {
                res[0].push_back(player);
            }
            if (lostTime[player] == 1) {
                res[1].push_back(player);
            }
        }
        return res;
    }
};