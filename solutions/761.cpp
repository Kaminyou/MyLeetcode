class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> v;
        int cnt = 0;
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '1') cnt++;
            else cnt--;
            if (cnt == 0) {
                v.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        string res;
        for (auto& subS : v) res += subS;
        return res;
    }
};