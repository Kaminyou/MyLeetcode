class Solution {
public:
    string parseStr(string& str, int maxZero, int maxOne) {
        int zeroCnt = 0;
        int oneCnt = 0;
        int questionCnt = 0;
        int n = str.size();
        for (int j = 0; j < n; ++j) {
            if (str[j] == '0') zeroCnt++;
            if (str[j] == '1') oneCnt++;
            if (str[j] == '?') questionCnt++;
        }
        if (zeroCnt > maxZero) return "";
        if (oneCnt > maxOne) return "";
        int zeroQuota = maxZero - zeroCnt;
        string str2 = str;
        for (int j = 0; j < n; ++j) {
            if (str[j] == '?') {
                if (zeroQuota > 0) {
                    str2[j] = '0';
                    zeroQuota--;
                }
                else {
                    str2[j] = '1';
                }
            }
        }
        return str2;
    }
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> oneMinusZero(n, 0);
        int sZeroCnt = 0;
        int sOneCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') sZeroCnt++;
            else sOneCnt++;
            oneMinusZero[i] = sOneCnt - sZeroCnt;
        }
        int m = strs.size();
        vector<bool> res(m, false);
        for (int i = 0; i < m; ++i) {
            string str = parseStr(strs[i], sZeroCnt, sOneCnt);
            if (str == "") {
                res[i] = false;
                continue;
            }
            int oneCnt = 0;
            int zeroCnt = 0;
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (str[j] == '0') zeroCnt++;
                if (str[j] == '1') oneCnt++;
                if (oneCnt - zeroCnt > oneMinusZero[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res[i] = true;
        }
        return res;
    }
};

