class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a') return true;
        if (c == 'e') return true;
        if (c == 'i') return true;
        if (c == 'o') return true;
        if (c == 'u') return true;
        return false;
    }
    int maxFreqSum(string s) {
        int hash[26];
        int maxVowel = 0;
        int maxConsonant = 0;
        for (auto& c : s) {
            hash[c - 'a']++;
            if (isVowel(c)) maxVowel = max(maxVowel, hash[c - 'a']);
            else maxConsonant = max(maxConsonant, hash[c - 'a']);
        }
        return maxVowel + maxConsonant;
    }
};
