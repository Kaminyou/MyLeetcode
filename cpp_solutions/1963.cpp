class Solution {
public:
    int minSwaps(string s) {
        if (s.size() == 0) return 0;
        int open = 0;
        int close = 0;
        int left = 0;
        int right = s.size() - 1;
        int cnt = 0;
        while (s[right] != '[') right--;
        while (left < right) {
            if (s[left] == '[') open++;
            else close++;
            if (close > open) {
                s[left] = '[';
                s[right] = ']';
                cnt++;
                close--;
                open++;
                while (s[right] != '[') right--;
            }
            left++;
        }
        return cnt;
    }
};
