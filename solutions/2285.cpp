class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> outDegree(n, 0);
        // iterate each edge and collect outDegree
        for (auto road : roads) {
            outDegree[road[0]]++;
            outDegree[road[1]]++;
        }
        sort(outDegree.begin(), outDegree.end());
        // assign low node number to those node with low outDegree
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += outDegree[i] * (long long)(i + 1);
        }
        return sum;
    }
};