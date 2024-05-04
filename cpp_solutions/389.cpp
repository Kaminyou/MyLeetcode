class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> temp(26, 0);
        for (auto& c : t) {
            temp[c - 'a']++;
        }
        for (auto& c : s) {
            temp[c - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (temp[i]) return i + 'a';
        }
        return 'a';
    }
};