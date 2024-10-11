typedef pair<int, int> P;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int, vector<int>, greater<int>> empty;
        priority_queue<P, vector<P>, greater<P>> full;
        int n = times.size();
        for (int i = 0; i < n; ++i) {
            empty.push(i);
            times[i].push_back(i);
        }
        sort(times.begin(), times.end());
        for (auto& time : times) {
            int start = time[0];
            int end = time[1];
            int idx = time[2];
            while (!full.empty() && full.top().first <= start) {
                P p = full.top();
                full.pop();
                empty.push(p.second);
            }
            int pos = empty.top();
            empty.pop();
            full.push({end, pos});
            if (targetFriend == idx) return pos;
        }
        return -1;
    }
};
