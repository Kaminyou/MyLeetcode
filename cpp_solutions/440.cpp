class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k) {
            long long step = 0;
            long long first = curr;
            long long last = curr + 1;
            while (first <= n) {
                step += min((long long)n + 1 , last) - first;
                first *= 10;
                last *= 10;
            }
            if (step > k) {
                k -= 1;
                curr *= 10;
            }
            else {
                k -= step;
                curr += 1;
            }
        }
        return curr;
    }
};