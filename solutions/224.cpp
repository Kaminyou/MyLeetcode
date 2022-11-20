class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int sign = 1;
        stack<int> st;
        int index = 0;
        while (index < s.size()) {
            if (isdigit(s[index])) {
                int num = 0;
                num += s[index] - '0';
                while (index + 1 < s.size() && isdigit(s[index + 1])) {
                    index++;
                    num *= 10;
                    num += s[index] - '0';
                }
                res += sign * num;
            }
            else if (s[index] == '+') {
                sign = 1;
            }
            else if (s[index] == '-') {
                sign = -1;
            }
            else if (s[index] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if (s[index] == ')') {
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
            index++;
        }
        return res;
    }
};