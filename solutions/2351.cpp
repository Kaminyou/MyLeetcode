class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> hash(26, false);
        for (auto c : s) {
            if (hash[c - 'a'] == true) return c;
            hash[c - 'a'] = true;
        }
        return 'a';
    }
};