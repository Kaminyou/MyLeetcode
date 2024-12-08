class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        set<int> st;
        vector<vector<int>> ends;
        for (auto& event : events) {
            ends.push_back({event[1], event[2]});
        }
        sort(ends.begin(), ends.end());
        int n = events.size();
        int index = 0;
        int maxValue = 0;
        sort(events.begin(), events.end());
        for (auto& event : events) {
            int start = event[0];
            int end = event[1];
            int value = event[2];
            while (index < n && ends[index][0] < start) {
                st.insert(ends[index][1]);
                index++;
            }
            maxValue = max(maxValue, value);
            if (!st.empty()) {
                maxValue = max(maxValue, value + *st.rbegin());
            }
        }
        return maxValue;
    }
};
