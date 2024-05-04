class Solution {
public:
    int isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n / 2; ++i) {
            cnt += isVowel(s[i]);
        }
        for (int i = n / 2; i < n; ++i) {
            cnt -= isVowel(s[i]);
        }
        
        return cnt == 0;
    }
};