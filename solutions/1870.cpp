class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() - 1 >= hour) return -1;
        int maxDist = *max_element(dist.begin(), dist.end());
        if (dist.size() == hour) return maxDist;
        int left = 1;
        int right = maxDist * 100;
        while (left < right) {
            int mid = left + (right - left) / 2;
            double time = 0.0;
            int n = dist.size();
            for (int i = 0; i < n; ++i) {
                int d = dist[i];
                if (i < n - 1) time += (d - 1) / mid + 1;
                else time += double(d) / (double)mid;
            }
            if (time <= hour) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};