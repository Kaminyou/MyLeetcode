class Solution {
public:
    long long guessX(long long workerTime, long long limitTime) {
        long long left = 0;
        long long right = INT_MAX >> 12;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (mid * (mid + 1) / 2 * workerTime > limitTime) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
    long long valid(long long limitTime, long long mountainHeight, vector<int>& workerTimes) {
        long long sum = 0;
        for (auto workerTime : workerTimes) {
            sum += guessX(workerTime, limitTime);
        }
        return sum >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0;
        long long right = LLONG_MAX / 2;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (valid(mid, mountainHeight, workerTimes)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

