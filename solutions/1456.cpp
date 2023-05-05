class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int res = 0;
        int count = 0;
        for (int i = 0; i < k - 1; ++i) {
            if (isVowel(s[i])) count++;
        }
        for (int i = k - 1; i < s.size(); ++i) {
            if (isVowel(s[i])) count++;
            res = max(res, count);
            if (isVowel(s[i - k + 1])) count--;
        }
        return res;
    }
};