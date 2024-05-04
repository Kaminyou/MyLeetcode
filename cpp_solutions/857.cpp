class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double qualitySum = 0.0;
        int n = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; ++i) {
            workers.push_back(make_pair(static_cast<double>(wage[i]) / quality[i], quality[i]));
        }
        
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        double res = DBL_MAX;
        for (auto worker : workers) {
            pq.push(worker.second);
            qualitySum += worker.second;
            while (pq.size() > k) {
                qualitySum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                res = min(res, qualitySum * worker.first);
            }
        }
        return res;
    }
};