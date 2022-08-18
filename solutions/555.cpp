class Solution {
public:
    string getLarger(string& s) {
        string sR = s;
        reverse(sR.begin(), sR.end());
        if (s > sR) return s;
        else return sR;
    }
    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            strs[i] = getLarger(strs[i]);
        }
        
        string middleString;
        for (int i = 0; i < n; ++i) {
            middleString += strs[i];
        }
        
        string maxString = "";
        for (int i = 0; i < n; ++i) {
            middleString = middleString.substr(strs[i].size());
            string rev = strs[i];
            reverse(rev.begin(), rev.end());
            int m = rev.size();
            for (int j = 0; j < m; j++) {
                string s1 = strs[i].substr(j) + middleString + strs[i].substr(0, j);
                string s2 = rev.substr(j) + middleString + rev.substr(0, j);
                if (s1 > maxString) maxString = s1;
                if (s2 > maxString) maxString = s2;
            }
            
            middleString += strs[i];
        }
        
        return maxString;
    }
};