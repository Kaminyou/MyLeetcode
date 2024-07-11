class Solution {
public:
    string _reverse(string& s, int& index, bool isReverse) {
        string out = "";
        int n = s.size();
        while (index < n) {
            if (s[index] == ')') {
                index++;
                break;
            }
            else if (s[index] == '(') {
                index++;
                string append = _reverse(s, index, true);
                out += append;
            }
            else {
                out.push_back(s[index]);
                index++;
            }
        }

        if (isReverse) {
            reverse(out.begin(), out.end());
        }
        return out;
    }
    string reverseParentheses(string s) {
        int index = 0;
        return _reverse(s, index, false);
    }
};
