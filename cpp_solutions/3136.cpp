class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
    bool isConsonant(char c) {
        if (isVowel(c)) return false;
        int n = c - 'a';
        if (n >= 0 && n < 26) return true;
        n = c - 'A';
        if (n >= 0 && n < 26) return true;
        return false;
    }
    bool isDigitAlpha(char c) {
        int n = c - 'a';
        if (n >= 0 && n < 26) return true;
        n = c - 'A';
        if (n >= 0 && n < 26) return true;
        n = c - '0';
        if (n >= 0 && n < 10) return true;
        return false;
    }
    bool isValid(string word) {
        int cnt = 0;
        bool isDigitAlphaOnly = true;
        bool hasVowel = false;
        bool hasConsonant = false;
        for (auto& c : word) {
            if (isVowel(c)) {
                hasVowel = true;
            }
            if (isConsonant(c)) {
                hasConsonant = true;
            }
            cnt++;
            if (!isDigitAlpha(c)) {
                isDigitAlphaOnly = false;
            }
        }
        return cnt >= 3 && isDigitAlphaOnly && hasVowel && hasConsonant;
    }
};
