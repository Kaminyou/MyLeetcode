class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (right > left) {
            if (s[right] != s[left]) return false;
            right--;
            left++;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if (s.size() == 0) return 0;
        if (isPalindrome(s)) return 1;
        else return 2;
    } 
};