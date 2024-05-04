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

// v2
class Solution {
public:
    bool allLarger(vector<int>& s1Hash, vector<int>& substringHash) {
        for (int i = 0; i < 26; ++i) {
            if (substringHash[i] < s1Hash[i]) return false;
        }
        return true;
    }
    bool allMatch(vector<int>& s1Hash, vector<int>& substringHash) {
        for (int i = 0; i < 26; ++i) {
            if (substringHash[i] != s1Hash[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Hash(26, 0);
        for (auto& c : s1) s1Hash[c - 'a']++;

        int m = s1.size();
        int n = s2.size();
        int left = 0;
        vector<int> substringHash(26, 0);
        for (int right = 0; right < n; ++right) {
            substringHash[s2[right] - 'a']++;
            if (right - left + 1 == m && allMatch(s1Hash, substringHash)) return true;
            while (allLarger(s1Hash, substringHash)) {
                substringHash[s2[left] - 'a']--;
                left++;
                if (right - left + 1 == m && allMatch(s1Hash, substringHash)) return true;
            }
        }
        return false;
    }
};