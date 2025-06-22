class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int cnt = (n + k - 1) / k;
        vector<string> res;
        int index = 0;
        for (int i = 0; i < cnt; ++i) {
            string ss = "";
            for (int j = 0; j < k; ++j) {
                if (index >= n) ss.push_back(fill);
                else {
                    ss.push_back(s[index]);
                    index++;
                }
            }
            res.push_back(ss);
        }
        return res;
    }
};

