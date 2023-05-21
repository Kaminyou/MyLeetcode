class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                char c = min(s[left], s[right]);
                s[left] = s[right] = c;
            }
            left++;
            right--;
        }
        return s;
    }
};