class Solution {
public:
    bool dp(string& s1, string& s2, int length, int s1Idx, int s2Idx, vector<vector<vector<int>>>& memo) {
        if (length == 1) return s1[s1Idx] == s2[s2Idx];
        if (memo[s1Idx][s2Idx][length] != -1) return memo[s1Idx][s2Idx][length];
        
        vector<int> count(26, 0);
        for (int i = 0; i < length; ++i) {
            count[s1[s1Idx + i] - 'a']++;
            count[s2[s2Idx + i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) return memo[s1Idx][s2Idx][length] = 0;
        }
        
        for (int i = 1; i < length; ++i) {
            // [s1Idx, s1Idx] to [s1Idx, s1Idx + length - 1]
            // no change
            bool left = dp(s1, s2, i, s1Idx, s2Idx, memo);
            bool right = dp(s1, s2, length - i, s1Idx + i, s2Idx + i, memo);
            if (left && right) return memo[s1Idx][s2Idx][length] = 1;
            
            // exchange
            left = dp(s1, s2, i, s1Idx, s2Idx + length - i, memo);
            right = dp(s1, s2, length - i, s1Idx + i, s2Idx, memo);
            if (left && right) return memo[s1Idx][s2Idx][length] = 1;
        }
        return memo[s1Idx][s2Idx][length] = 0;
    }
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        int n = s1.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return dp(s1, s2, n, 0, 0, memo);
    }
};