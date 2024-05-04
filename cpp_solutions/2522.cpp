class Solution {
public:
    int minimumPartition(string s, int k) {
        int cnt = 0;
        int n = s.size();
        int index = 0;
        while (index < n) {
            int start = index;
            long long num = s[index] - '0';
            while (index + 1 < n && (num * 10+ (s[index + 1] - '0')) <= k) {
                index++;
                num *= 10;
                num += s[index] - '0';
            }
            if (num > k) return -1;
            cnt++;
            index++;
        }
        return cnt;
    }
};