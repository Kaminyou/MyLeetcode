class Solution {
public:
    bool criteria(long long time, vector<int>& ranks, int cars) {
        long long count = 0;
        for (auto& rank : ranks) {
            long long hasTime = time / rank;
            double cnt = sqrt(hasTime);
            count += static_cast<long long>(cnt);
        }
        return count >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0;
        long long right = LLONG_MAX;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (criteria(mid, ranks, cars)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
