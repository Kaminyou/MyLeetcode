typedef pair<int, int> P; // length, end
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> queriesCopy = queries;
        sort(queries.begin(), queries.end());
        
        priority_queue<P, vector<P>, greater<P>> pq; // min heap
        int index = 0;
        int n = intervals.size();
        
        unordered_map<int, int> mp;
        for (auto& query : queries) {
            while (index < n && intervals[index][0] <= query) {
                pq.push({intervals[index][1] - intervals[index][0] + 1, intervals[index][1]});
                index++;
            }
            while (!pq.empty() && pq.top().second < query) pq.pop();
            if (pq.empty()) mp[query] = -1;
            else mp[query] = pq.top().first;
        }
        
        int m = queries.size();

        vector<int> res(m, 0);
        for (int i = 0; i < m; ++i) {
            res[i] = mp[queriesCopy[i]];
        }
        return res;
    }
};