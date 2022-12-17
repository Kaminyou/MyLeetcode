class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (auto& token : tokens) {
            if (token == "+") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if (token == "-") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (token == "*") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(b * a);
            }
            else if (token == "/") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(b / a);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};