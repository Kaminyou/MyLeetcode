class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = INT_MIN;
        int a = 0;
        int b = 0;
        int n = values.size();
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                res = max(res, a + values[i] - i);
            }
            a = max(a, values[i] + i);
        }
        return res;
    }
};

