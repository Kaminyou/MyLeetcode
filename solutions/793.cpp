class Solution {
public:
    int cntZero(long long num) {
        int cnt = 0;
        while (num > 0) {
            cnt += num / 5;
            num /= 5;
        }
        return cnt;
    }
    int preimageSizeFZF(int k) {
        long long left = 0;
        long long right = 5 * 1e9 + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (cntZero(mid) >= k) right = mid;
            else left = mid + 1;
        }
        if (cntZero(left) == k) return 5;
        return 0;
    }
};
