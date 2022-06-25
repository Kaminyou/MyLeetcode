class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> counts(26, 0);
        for (auto& c : s) counts[c - 'a']++;
        for (auto& c : t) {
            counts[c - 'a']--;
            if (counts[c - 'a'] < 0) return false;
        }
        return true;
    }
};