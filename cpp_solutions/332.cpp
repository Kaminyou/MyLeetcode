class Solution {
public:
    bool backtracking(vector<string>& path, unordered_map<string, map<string, int>>& mp, int n) {
        if (path.size() == n) return true;
        for (auto& element : mp[path[path.size() - 1]]) {
            if (element.second > 0) {
                element.second--;
                path.push_back(element.first);
                if (backtracking(path, mp, n)) return true;
                path.pop_back();
                element.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size() + 1;
        unordered_map<string, map<string, int>> mp;
        for (auto& ticket : tickets) {
            mp[ticket[0]][ticket[1]]++;
        }

        vector<string> path = {"JFK"};
        backtracking(path, mp, n);
        return path;
    }
};
