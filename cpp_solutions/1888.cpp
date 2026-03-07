class Solution {
public:
    vector<int> _minFlips(string& s, int now) {
        // change # of times if end by s[i]
        int n = s.size();
        vector<int> res(n, 0);
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c - '0' != now) curr++;
            now ^= 1;
            res[i] = curr;
        }
        return res;
    }
    int minFlips(string s) {
        int n = s.size();
        vector<int> startByZero = _minFlips(s, 0);
        vector<int> startByOne = _minFlips(s, 1);
        reverse(s.begin(), s.end());
        vector<int> endByZero = _minFlips(s, 0);
        vector<int> endByOne = _minFlips(s, 1);
        reverse(endByZero.begin(), endByZero.end());
        reverse(endByOne.begin(), endByOne.end());

        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (i >= 1) {
                res = min(res, endByZero[i] + startByOne[i - 1]);
                res = min(res, endByOne[i] + startByZero[i - 1]);
            }
            else {
                res = min(res, endByZero[i] + 0);
                res = min(res, endByOne[i] + 0);
            }
        }
        
        return res;
    }
};


