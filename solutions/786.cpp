class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0;
        double right = 1;
        
        while (true) {
            double mid = left + (right - left) / 2;
            int cnt = 0;
            int p = 0;
            int q = 0;
            int j = 1;
            double maxFrac = 0;
            for (int i = 0; i < n - 1; ++i) {
                while (j < n && arr[i] > mid * arr[j]) j++;
                cnt += (n - j);
                if (j == n) break;
                double f = (double)arr[i] / arr[j];
                if (f > maxFrac) {
                    p = i;
                    q = j;
                    maxFrac = f;
                }
            }
            if (cnt == k) {
                return {arr[p], arr[q]};
            }
            else if (cnt > k) right = mid;
            else left = mid;
        }
        return {};
    }
};