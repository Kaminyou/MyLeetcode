class Solution {
public:
    int left;
    int right;
    int n;
    
    bool checkVowel(char c) {
        if (c == 'a' || c == 'A') return true;
        if (c == 'e' || c == 'E') return true;
        if (c == 'i' || c == 'I') return true;
        if (c == 'o' || c == 'O') return true;
        if (c == 'u' || c == 'U') return true;
        return false;
    }
    void getNextLeft(string& s) {
        while (left < n - 1 && !checkVowel(s[left + 1])) left++;
        left++;
    }
    void getNextRight(string& s) {
        while (right > 0 && !checkVowel(s[right - 1])) right--;
        right--;
    }
    string reverseVowels(string s) {
        left = -1;
        right = s.size();
        n = s.size();
        
        getNextLeft(s);
        getNextRight(s);
        while (left < right) {
            swap(s[left], s[right]);
            getNextLeft(s);
            getNextRight(s);
        }
        return s;
    }
};