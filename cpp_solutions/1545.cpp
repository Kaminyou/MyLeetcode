class Solution {
public:
    void oper(string& s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        reverse(s.begin(), s.end());
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 2; i <= n; ++i) {
            string ss = s;
            oper(s);
            string temp = ss + "1" + s;
            s = temp;
        }
        return s[k - 1];
    }
};
