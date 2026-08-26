class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int length = INT_MAX;
        string res = "";
        int left = 0;
        int cnt = 0;
        int n = s.size();
        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') cnt++;
            if (left <= right && cnt > k) {
                if (s[left] == '1') {
                    cnt--;
                    left++;
                }
            }
            while (s[left] == '0') left++;
            // [left, right]
            if (cnt == k) {
                int l = right - left + 1;
                if (l < length) {
                    length = l;
                    res = s.substr(left, l);
                }
                else if (l == length){
                    string sub = s.substr(left, l);
                    if (sub < res) res = sub;
                }
            }
        }
        return res;
    }
};
