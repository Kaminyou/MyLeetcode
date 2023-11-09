class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int index = 0;
        long long ans = 0;
        long long mod = 1e9 + 7;
        while (index < n) {
            int start = index;
            char c = s[index];
            while (index + 1 < n && s[index + 1] == c) index++;
            long long length = index - start + 1;
            ans += (length + 1) * length / 2;
            ans %= mod;
            index++;
        }
        return ans;
    }
};
