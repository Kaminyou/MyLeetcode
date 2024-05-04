class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int index = 0;
        while (index < s.size()) {
            if (s[index] != ' ') {
                while (index + 1 < s.size() && s[index + 1] != ' ') index++;
                count++;
            }
            index++;
        }
        return count;
    }
};