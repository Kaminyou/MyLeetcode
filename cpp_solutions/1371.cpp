class Solution {
public:
    int toBitmask(char& c) {
        if (c == 'a') {
            return 1;
        }
        if (c == 'e') {
            return 1 << 1;
        }
        if (c == 'i') {
            return 1 << 2;
        }
        if (c == 'o') {
            return 1 << 3;
        }
        if (c == 'u') {
            return 1 << 4;
        }
        return 0;
    }
    int findTheLongestSubstring(string s) {
        int currentMask = 0;
        int length = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            currentMask ^= toBitmask(s[i]);
            if (mp.count(currentMask)) {
                length = max(length, i - mp[currentMask]);
            }
            else {
                mp[currentMask] = i;
            }
        }
        return length;
    }
};
