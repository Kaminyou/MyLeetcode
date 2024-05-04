class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<vector<int>> positions(26);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            positions[s[i] - 'a'].push_back(i);
        }
        
        for (int i = 0; i < 26; ++i) {
            if (positions[i].size() == 0) continue;
            if (positions[i][1] - positions[i][0] - 1 != distance[i]) return false;
        }
        return true;
    }
};