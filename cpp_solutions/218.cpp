class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<int>> position2heights;
        for (auto& building : buildings) {
            position2heights[building[0]].push_back(building[2]);
            position2heights[building[1]].push_back(-building[2]);
        }
        
        multiset<int> st;
        st.insert(0);
        int current = 0;
        vector<vector<int>> res;
        for (auto& [position, heights] : position2heights) {
            for (auto& height : heights) {
                if (height > 0) {
                    st.insert(height);
                }
                else {
                    st.erase(st.find(-height));
                }
            }
            int next = *st.rbegin();
            if (next == current) continue;
            else {
                current = next;
                res.push_back({position, current});
            }
        }
        return res;
    }
};
