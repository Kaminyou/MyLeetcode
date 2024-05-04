class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = -1;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            if (word[i] == ch) {
                pos = i;
                break;
            }
        }
        if (pos == -1) return word;
        reverse(word.begin(), word.begin() + pos + 1);
        return word;
    }
};
