class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = 0;
        int n = s.size();
        int res = 0;
        while (index < n) {
            if (s[index] == ' ') index++;
            else {
                int start = index;
                while (index + 1 < n && s[index + 1] != ' ') index++;
                res = index - start + 1;
                index++;
            }
        }
        return res;
    }
};