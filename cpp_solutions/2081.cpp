class Solution {
public:
    int vec[100];
    long long kMirror(int k, int n) {
        int length = 1;
        long long sum = 0;
        int cnt = 0;
        while (true) {
            int low = pow(10, length - 1);
            int high = pow(10, length);
            for (int i = low; i < high; ++i) {
                long long mirror = make(i, 0);
                if (check(mirror, k)) {
                    sum += mirror;
                    cnt++;
                }
                if (cnt == n) return sum;
            }
            for (int i = low; i < high; ++i) {
                long long mirror = make(i, 1);
                if (check(mirror, k)) {
                    sum += mirror;
                    cnt++;
                }
                if (cnt == n) return sum;
            }
            length++;
        }
        return -1;
    }
    long long make(long long num, bool flag) {
        long long temp = num;
        long long appendix = 0;
        int cnt = 0;
        while (temp) {
            appendix = appendix * 10 + temp % 10;
            temp /= 10;
            cnt++;
        }
        if (!flag) num /= 10;
        while (cnt--) num *= 10;
        return num + appendix;
    }
    bool check(long long num, int k) {
        int t = 0;
        while (num) {
            vec[t++] = num % k;
            num /= k;
        }
        int left = 0;
        int right = t - 1;
        while (left < right) {
            if (vec[left] != vec[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
