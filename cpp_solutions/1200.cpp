class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int minDiff = INT_MAX;
        for (int i = 0; i < n - 1; ++i) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - arr[i] == minDiff) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};
