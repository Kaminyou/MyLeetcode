class Solution {
public:
    string parser(string& s, int& index) {
        char select = s[index];
        index += 2;
        // true select
        string trueStr;
        if (s[index + 1] == '?') {
            trueStr = parser(s, index);
            index++; // skip :
        }
        else {
            trueStr = s[index];
            index += 2; // skip self + :
        }
        // false select
        string falseStr;
        if (index + 1 < s.size() && s[index + 1] == '?') {
            falseStr = parser(s, index);
        }
        else {
            falseStr = s[index];
            index += 1; // skip self
        }

        if (select == 'T') return trueStr;
        else return falseStr;
    }

    string parseTernary(string expression) {
        int index = 0;
        return parser(expression, index);
    }
};