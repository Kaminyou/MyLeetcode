class Solution {
public:
    string smallestGoodBase(string n) {
        long long nInt = stoll(n);
        for (int length = log2(nInt + 1); length >= 3; --length) {
            int left = 2;
            int right = pow(nInt, 1.0 / (length - 1)) + 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                long long sum = 0;
                for (int i = 0; i < length; ++i) {
                    sum = sum * mid + 1;
                }
                if (sum == nInt) return to_string(mid);
                if (sum >= nInt) right = mid;
                else left = mid + 1;
            }
        }
        return to_string(nInt - 1);
    }
};
// 1 + b ^ 1 + b ^ 2 + ... + b ^ (m - 1) = n
// n * (b - 1) = b ^ m - 1
// m = [3, log2(n + 1)]
// given m:  b = [2, n^((1/m - 1)) + 1]