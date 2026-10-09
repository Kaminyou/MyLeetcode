class Solution {
public:
    int minInsertions(string s) {
        int append = 0;
        int index = 0;
        int n = s.size();
        int curr = 0;
        while (index < n) {
            if (s[index] == '(') {
                curr += 2;
                index++;
            }
            else {
                if (index + 1 >= n) {
                    curr -= 2;
                    append += 1;
                    index++;
                }
                else if (s[index + 1] == ')') {
                    curr -= 2;
                    index += 2;
                }
                else {
                    curr -= 2;
                    append += 1;
                    index++;
                }
            }
            if (curr < 0) {
                append += abs(curr) / 2;
                curr = 0;
            }
        }
        if (curr > 0) append += curr;
        return append;
    }
};
