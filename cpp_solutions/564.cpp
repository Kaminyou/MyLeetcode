class Solution {
public:
    string nearestPalindromic(string n) {
        int size = n.size();
        long long num = stoll(n);
        unordered_set<long long> st;
        st.insert(pow(10, size) + 1);
        st.insert(pow(10, size - 1) - 1);
        
        if (size & 1) {
            string half = n.substr(0, size / 2 + 1);
            long long prefix = stoll(half);
            for (int i = -1; i <= 1; ++i) {
                string prefixNew = to_string(prefix + i);
                string rev = prefixNew.substr(0, prefixNew.size() - 1);
                reverse(rev.begin(), rev.end());
                string temp = prefixNew + rev;
                st.insert(stoll(temp));
            }
        }
        else {
            string half = n.substr(0, size / 2);
            long long prefix = stoll(half);
            for (int i = -1; i <= 1; ++i) {
                string prefixNew = to_string(prefix + i);
                string rev = prefixNew;
                reverse(rev.begin(), rev.end());
                string temp = prefixNew + rev;
                st.insert(stoll(temp));
            }
        }
        long long minDiff = LLONG_MAX;
        string res;
        for (auto& value : st) {
            if (value == num) continue;
            if (abs(num - value) < minDiff) {
                minDiff = abs(num - value);
                res = to_string(value);
            }
            else if (abs(num - value) == minDiff) {
                long long temp = stoll(res);
                if (value < temp) res = to_string(value);
            }
        }
        return res;
    }
};