class Solution {
public:
    void getSmallest(string& s, int a, int startIdx) {
        int curr = s[startIdx] - '0';
        int min = 9;
        int time = 0;
        for (int i = 0; i < 11; ++i) {
            curr += a;
            curr %= 10;
            if (curr < min) {
                min = curr;
                time = i + 1;
            }
        }
        for (int i = startIdx; i < s.size(); i += 2) {
            s[i] = (((s[i] - '0') + a * time) % 10) + '0';
        }
    }
    string findLexSmallestString(string s, int a, int b) {
        string res = string(s.size(), '9');
        for (int i = 0; i < s.size() + 1; ++i) {
            if (b & 1) getSmallest(s, a, 0);
            getSmallest(s, a, 1);
            if (s < res) {
                res = s;
            }
            s = s.substr(s.size() - b) + s.substr(0, s.size() - b);
        }
        return res;
    }
};

