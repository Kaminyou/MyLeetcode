class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long mod = 1e9 + 7;
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; ++i) {
            engineers.push_back(make_pair(efficiency[i], speed[i]));
        }
        sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());
        
        priority_queue<int, vector<int>, greater<int>> pq; // min Heap
        
        long long ans = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            pq.push(engineers[i].second);
            sum += engineers[i].second;
            if (i >= k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * engineers[i].first);
        }
        return ans % mod;
    }
};