class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val = 0;
        int count = 0;
        int pow = 1;
        for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i) {
            if (s[i] == '1') {
                count++;
                val += pow;
            }
            pow <<= 1;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') count++;
        }
        return count;
    }
};

class Solution {
public:
    bool check(string s, string t, int indexS, int indexT) {
        if (indexS == s.size()) return true;
        if (s[indexS] < t[indexT]) return true;
        if (s[indexS] > t[indexT]) return false;
        return check(s, t, indexS + 1, indexT + 1);
    }
    int longestSubsequence(string s, int k) {
        string t = "";
        while (k) {
            if (k & 1) t.push_back('1');
            else t.push_back('0');
            k /= 2;
        }
        reverse(t.begin(), t.end());
        int m = s.size();
        int n = t.size();
        if (n > m) return m;
        int kk = m - n;
        int zeros = 0;
        for (int i = 0; i < kk; ++i) {
            if (s[i] == '0') zeros++;
        }
        if (check(s, t, kk, 0)) {
            return n + zeros;
        }
        return n + zeros - 1;
    }
};

