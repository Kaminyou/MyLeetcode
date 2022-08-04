class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int, int>> st;
        long long area = 0;
        for (auto& rectangle : rectangles) {
            pair<int, int> a = make_pair(rectangle[0], rectangle[1]);
            pair<int, int> b = make_pair(rectangle[2], rectangle[1]);
            pair<int, int> c = make_pair(rectangle[0], rectangle[3]);
            pair<int, int> d = make_pair(rectangle[2], rectangle[3]);
            for (auto& p : {a, b, c, d}) {
                if (st.find(p) != st.end()) st.erase(p);
                else st.insert(p);
            }
            area += (long long)(rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
        }
        
        if (st.size() != 4) return false;
        pair<int, int> lo = *st.begin();
        pair<int, int> hi = *st.rbegin();
        return (long long)(hi.first - lo.first) * (hi.second - lo.second) == area;
    }
};