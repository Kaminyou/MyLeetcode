class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 == str2) return str1;
        if (str1.size() < str2.size()) {
            swap(str1, str2);
        }
        int n = str1.size();
        int m = str2.size();
        for (int i = 0; i < m; ++i) {
            if (str1[n - i - 1] != str2[m - i - 1]) return "";
        }
        return gcdOfStrings(str1.substr(0, n - m), str2);
    }
};