class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        int index = 0;
        while (index < s.size()) {
            if (s[index] == '*') {
                count++;
                index++;
            }
            else if (s[index] == '|') {
                int start = index;
                index++;
                while (s[index] != '|') index++;
                index++;                
            }
            else {
                index++;
            }
        }
        return count;
    }
};