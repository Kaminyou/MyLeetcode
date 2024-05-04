class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        for (auto candidate : candidates) {
            int l = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            int r = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            if ((r - l) * 4 > n) return candidate;
        }
        return -1;
    }
};
