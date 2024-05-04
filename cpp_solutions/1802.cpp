class Solution {
public:
    long long getSum(long long n, long long index, long long target) {
        long long sum = n * target - (1 + index) * index / 2 - (n - index) * (n - 1 - index) / 2;
        if (target - index < 1) {
            long long below = 1 + index - target;
            sum += (below + 1) * below / 2;
        }
        if (target - (n - 1 - index) < 1) {
            long long below = 1 + n - 1 - index - target;
            sum += (below + 1) * below / 2;
        }
        return sum;
    }
    int maxValue(int n, int index, int maxSum) {
        long long left = 0;
        long long right = LLONG_MAX / n;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long sum = getSum(n, index, mid);
            if (sum > (long long)maxSum) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};
