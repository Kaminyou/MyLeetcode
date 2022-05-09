class Solution {
public:
    bool isEqual(const vector<int>& hash1, const vector<int>& hash2) {
        for (int i = 0; i < 26; i++) {
            if (hash1[i] != hash2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) return false;
        vector<int> s1Hash(26, 0);
        vector<int> s2Hash(26, 0);
        for (int i = 0; i < m; i++) s1Hash[s1[i] - 'a']++;
        for (int i = 0; i < m - 1; i++) s2Hash[s2[i] - 'a']++;
        
        for (int i = m - 1; i < n; i++) {
            s2Hash[s2[i] - 'a']++;
            if (isEqual(s1Hash, s2Hash)) return true;
            s2Hash[s2[i - m + 1] - 'a']--;
        }
        return false;
    }
};