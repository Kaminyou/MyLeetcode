class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";
        
        // count a
        int aCnt = 0;
        int notAIdx = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (palindrome[i] == 'a') aCnt++;
            else notAIdx = min(notAIdx, i);
        }
        if (aCnt == n) {
            palindrome[n - 1] = 'b';
            return palindrome;
        }
        
        // find first not a
        if (n & 1) {
            if (notAIdx == n / 2) {
                palindrome[n - 1] = 'b';
                return palindrome;
            }
            else {
                palindrome[notAIdx] = 'a';
                return palindrome;
            }
        }
        else {
            palindrome[notAIdx] = 'a';
            return palindrome;
        }
    }
};
