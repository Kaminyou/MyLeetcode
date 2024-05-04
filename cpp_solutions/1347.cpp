class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sHash(26, 0);
        vector<int> tHash(26, 0);
        for (auto& c : s) {
            sHash[c - 'a']++;
        }
        for (auto& c : t) {
            tHash[c - 'a']++;
        }
        int sum = 0;
        for (int i = 0; i < 26; ++i) {
            sum += abs(sHash[i] - tHash[i]);
        }
        return sum / 2;
    }
};
