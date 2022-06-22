class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& slot : slots1) {
            if (slot[1] - slot[0] >= duration) {
                pq.push(make_pair(slot[0], slot[1]));
            }
        }
        for (auto& slot : slots2) {
            if (slot[1] - slot[0] >= duration) {
                pq.push(make_pair(slot[0], slot[1]));
            }
        }
        while (pq.size() > 1) {
            auto slotMin = pq.top();
            pq.pop();
            auto slotCurr = pq.top();
            if (slotMin.second - slotCurr.first >= duration) {
                return {slotCurr.first, slotCurr.first + duration};
            }
        }
        return {};
    }
};