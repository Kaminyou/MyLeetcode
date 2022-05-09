class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int res = 0;
        int curr = INT_MIN;
        for (auto pair : pairs) {
            if (pair[0] > curr) {
                curr = pair[1];
                res++;
            }
        }
        return res;
    }
};