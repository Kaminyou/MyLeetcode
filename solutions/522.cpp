class Solution {
public:
    bool isSubsequence(string& s1, string& s2) {
        // s2 is s1's subsequence?
        if (s1 == s2) return true;
        if (s1.size() <= s2.size()) return false;
        // s1 size > s2 size
        int idx2 = 0;
        for (int idx1 = 0; idx1 < s1.size(); idx1++) {
            if (s1[idx1] == s2[idx2]) idx2++;
            if (idx2 == s2.size()) return true;
        }
        return false;
        
    }
    int findLUSlength(vector<string>& strs) {
        vector<vector<string>> len2strs(11);
        for (auto& str : strs) {
            int n = str.size();
            len2strs[n].push_back(str);
        }
        for (int i = 10; i >= 1; --i) {
            int m = len2strs[i].size();
            if (m == 0) continue;
            
            
            for (int j = 0; j < m; ++j) {
                bool isSub = false;
                // check between
                for (int k = 0; k < m; ++k) {
                    if (j == k) continue;
                    if (isSubsequence(len2strs[i][j], len2strs[i][k])) {
                        isSub = true;
                        break;
                    }
                }
                // check before
                if (!isSub) {
                    for (int t = 10; t > i; t--) {
                        int mm = len2strs[t].size();
                        for (int k = 0; k < mm; ++k) {
                           if (isSubsequence(len2strs[t][k], len2strs[i][j])) {
                                isSub = true;
                                break;
                            } 
                        }
                        if (isSub) break;
                    }
                }
                if (!isSub) return i;
            }            
        }
        return -1;
    }
};