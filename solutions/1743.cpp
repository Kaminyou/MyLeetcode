class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> relationship;
        unordered_set<int> st;
        for (auto& p : adjacentPairs) {
            relationship[p[0]].push_back(p[1]);
            relationship[p[1]].push_back(p[0]);
        }
        int current = INT_MIN;
        for (auto& p : relationship) {
            if (p.second.size() == 1) {
                current = p.first;
                break;
            }
        }
        vector<int> res;
        while (true) {
            res.push_back(current);
            st.insert(current);
            for (auto& num : relationship[current]) {
                if (!st.count(num)) current = num;
            }
            if (relationship[current].size() == 1) break;
        }
        res.push_back(current);
        return res;
    }
};
