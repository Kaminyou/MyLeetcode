class Solution {
public:
    string smallestString(string s) {
        string alphabets = "abcdefghijklmnopqrstuvwxyz";

        int index = 0;
        int n = s.size();
        while (index < n) {
            if (s[index] != 'a') {
                int start = index;
                s[start] = alphabets[s[start] - 'a' - 1];
                while (index + 1 < n && s[index + 1] != 'a') {
                    index++;
                    s[index] = alphabets[s[index] - 'a' - 1];
                }
                return s;
            }
            index++;
        }
        s[n - 1] = 'z';
        return s;
    }
};