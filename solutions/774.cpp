class Solution {
public:
    bool criteria(vector<int>& stations, double mid, int k) {
        int n = stations.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            cnt += (stations[i + 1] - stations[i]) / mid;
        }
        return cnt <= k;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0;
        double right = 1e9;
        while (right - left >= 1e-6) {
            double mid = left + (right - left) / 2;
            if (criteria(stations, mid, k)) right = mid;
            else left = mid;
        }
        return left;
    }
};