lass Solution {
public:
    bool criteria(vector<int>& time, long long duration,int totalTrips) {
        long long count = 0;
        for (auto& bus : time) {
            count += duration / bus;
        }
        return count >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long maxTime = *max_element(time.begin(), time.end());
        long long left = 0;
        long long right = totalTrips * maxTime;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (criteria(time, mid, totalTrips)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};