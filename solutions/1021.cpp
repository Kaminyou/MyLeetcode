class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int index = 0;
        string res;
        int n = s.size();
        while (index < n) {
            int start = index;
            count++; // must be valid
            while (count > 0) {
                index++;
                if (s[index] == '(') count++;
                else count--;
            }
            // [start, index] is valid
            res += s.substr(start + 1, index - start + 1 - 2);
            index++;
        }
        return res;
    }
};