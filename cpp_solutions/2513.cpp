class Solution {
public:
    long long lcm(long long a, long long b) {
        return a * b / __gcd(a, b);
    }
    bool criteria(int num, int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int cnt1 = num - num / divisor1;
        int cnt2 = num - num / divisor2;
        int cnt3 = num - num / lcm(divisor1, divisor2);
        return cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && cnt3 >= (uniqueCnt1 + uniqueCnt2);
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long left = 0;
        long long right = INT_MAX;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (criteria(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
