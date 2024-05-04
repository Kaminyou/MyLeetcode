class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n, 0);
        for (int i = 0; i < n; ++i) {
            time[i] = dist[i] / speed[i];
            if (dist[i] % speed[i]) time[i] += 1;
        }
        sort(time.begin(), time.end());
        for (int i = 0; i < n; ++i) {
            if (i != 0 && i >= time[i]) return i;
        }
        return n;
    }
};
