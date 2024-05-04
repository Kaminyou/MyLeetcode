class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int index = 0;
        int n = s.size();
        while (index < n) {
            if (s[index] != ' ') {
                int start = index;
                while (index + 1 < n && s[index + 1] != ' ') index++;
                reverse(s.begin() + start, s.begin() + index + 1);
            }
            index++;
        }
    }
};