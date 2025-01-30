class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int currentTime = 0;
        int longTime = 0;
        int res = -1;
        for (auto& event : events) {
            int duration = event[1] - currentTime;
            currentTime = event[1];
            if (duration == longTime) {
                res = min(res, event[0]);
            }
            if (duration > longTime) {
                longTime = duration;
                res = event[0];
            }
        }
        return res;
    }
};
