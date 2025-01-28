class Solution {
public:
    bool criteria(string& s, int numOps, int length) {
        char curr = '2';
        int cnt = 0;
        int ops = 0;
        for (auto& c : s) {
            if (curr != c) {
                if (cnt > length) {
                    ops += (cnt - length - 1) / (length + 1) + 1;
                }
                cnt = 1;
                curr = c;
            }
            else {
                cnt++;
            }
        }
        if (cnt > length) ops += (cnt - length - 1) / (length + 1) + 1;
        // (n - k) / (k + 1) <= length
        // (k + 1) * length >= (n - k)
        // k * length + length >= n - k
        // k * length + k >= n - length
        // k * (length + 1) >= n - length
        // k >= (n - length) / (length + 1) => k = (n - length - 1) / (length + 1) + 1
        return ops <= numOps;
    }
    int cntOps(string& s, char start) {
        char curr = start;
        int cnt = 0;
        for (auto& c : s) {
            if (c != curr) cnt++;
            curr = (curr == '1') ? '0' : '1';
        }
        return cnt;
    }
    int minLength(string s, int numOps) {
        int zeroStart = cntOps(s, '0');
        if (zeroStart <= numOps) return 1;
        int oneStart = cntOps(s, '1');
        if (oneStart <= numOps) return 1;
        int left = 2;
        int right = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(s, numOps, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
