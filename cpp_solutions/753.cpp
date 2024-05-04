class Solution {
public:
    string crackSafe(int n, int k) {
        int count = pow(k, n);
        string res = string(n, '0');
        unordered_set<string> st;
        st.insert(res);
        
        for (int i = 0; i < count; ++i) {
            string prev = res.substr(res.size() - n + 1);
            prev.push_back('0');
            for (int j = k - 1; j >= 0; --j) {
                prev[prev.size() - 1] = (j + '0');
                if (st.find(prev) == st.end()) {
                    st.insert(prev);
                    res.push_back(j + '0');
                    break;
                }
            }
        }
        return res;
    }
};