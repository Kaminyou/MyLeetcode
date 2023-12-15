class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        unordered_map<string, int> outDegree;
        for (auto& path : paths) {
            st.insert(path[0]);
            st.insert(path[1]);
            outDegree[path[0]]++;
        }
        for (auto& city : st) {
            if (outDegree[city] == 0) return city;
        }
        return "";
    }
};
