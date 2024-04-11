class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        stack<int> st;
        for (auto& c : num) {
            int digit = c - '0';
            if (!st.empty() && digit >= st.top()) {
                st.push(digit);
            }
            else {
                while (!st.empty() && digit < st.top() && k) {
                    st.pop();
                    k--;
                }
                st.push(digit);
            }
        }

        while (k) {
            st.pop();
            k--;
        }

        string res = "";
        while (!st.empty()) {
            res.push_back(st.top() + '0');
            st.pop();
        }

        while (!res.empty() && res.back() == '0') res.pop_back();
        if (res.size() == 0) return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};
