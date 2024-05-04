class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long res = 0;
        int n = arr.size();
        for (int i = 0; i < k; ++i) {
            vector<int> cycle;
            for (int j = i; arr[j] != 0; j = (j + k) % n) {
                cycle.push_back(arr[j]);
                arr[j] = 0;
            }
            int m = cycle.size();
            if (m > 0) {
                sort(cycle.begin(), cycle.end());
                
                int mid = cycle[m / 2];
                for (auto num : cycle) {
                    res += abs(num - mid);
                }
            }
        }
        return res;
    }
};