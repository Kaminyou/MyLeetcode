class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        for (int i = 0; i < n; ++i) {
            double ratio = (double)classes[i][0] / (double)classes[i][1];
            double nextRatio = double(classes[i][0] + 1) / double(classes[i][1] + 1);
            pq.push({nextRatio - ratio, i});
        }
        while (extraStudents--) {
            auto p = pq.top();
            pq.pop();
            int i = p.second;
            classes[i][0]++;
            classes[i][1]++;
            double ratio = ((double)classes[i][0]) / ((double)classes[i][1]);
            double nextRatio = double(classes[i][0] + 1) / double(classes[i][1] + 1);
            pq.push({nextRatio - ratio, i});
        }
        double res = 0;
        for (int i = 0; i < n; ++i) {
            double ratio = (double)classes[i][0] / (double)classes[i][1];
            res += ratio;
        }
        return res / double(n);
    }
};

