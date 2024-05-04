class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        if (v1[1] == v2[1]) return v1[0] < v2[0];
        return v1[1] > v2[1];
    }
    int visibleMountains(vector<vector<int>>& peaks) {
        int n = peaks.size();
        if (n == 1) return 1;
        map<int, int> position2height;
        sort(peaks.begin(), peaks.end(), compare);
        set<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 && n > 1) {
                if ((peaks[i][0] == peaks[i - 1][0]) && (peaks[i][1] == peaks[i - 1][1])) {
                    st.insert({peaks[i][0], peaks[i][1]});
                    continue;
                }
            }
            else if (peaks[i][0] == peaks[i + 1][0] && peaks[i][1] == peaks[i + 1][1]) {
                st.insert({peaks[i][0], peaks[i][1]});
                continue;
            }
        }
        int count = 0;
        for (auto& peak : peaks) {
            int position = peak[0];
            int height = peak[1];
            auto it = position2height.upper_bound(position);
            if (it != position2height.end()) {
                if (it->second - (it->first - position) >= height) continue;
            }
            if (it != position2height.begin()) {
                it--;
                if (it->second - (position - it->first) >= height) continue;
            }
            if (st.find({peak[0], peak[1]}) == st.end()) count++;
            position2height[position] = height;
        }
        return count;
    }
};