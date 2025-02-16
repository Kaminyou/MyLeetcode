class Solution {
public:
    int maxOperations(string s) {
        reverse(s.begin(), s.end());
        int res = 0;
        int index = 0;
        int cnt = 0;
        int n = s.size();
        while (index < n) {
            if (s[index] == '1') res += cnt;
            else {
                while (index + 1 < n && s[index + 1] == '0') index++;
                cnt += 1;
            }
            index++;
        }
        return res;
    }
};
