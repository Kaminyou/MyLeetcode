class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> scores(n, 0);
        for (int i = 0; i < n; ++i) {
            scores[edges[i]] += i;
        }
        
        long long maxVal = 0;
        for (int i = 0; i < n; ++i) {
            maxVal = max(maxVal, scores[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (scores[i] == maxVal) return i;
        }
        return 0;
    }
};