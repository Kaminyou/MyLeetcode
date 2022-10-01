class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long N = 0;
        int idx = 0;
        while (N < k) {
            if (isdigit(s[idx])) {
                N *= (s[idx] - '0');
            }
            else {
                N++;
            }
            idx++;
        }
        
        while (idx--) {
            if (isdigit(s[idx])) {
                N /= (s[idx] - '0');
                k %= N;
            }
            else if (k == N || k == 0) {
                return string(1, s[idx]);
            }
            else {
                N--;
            }
        }
        return "";
    }
};