class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> counts(26, 0);
        for (auto& c : s ) {
            counts[c - 'a']++;
        }
        int minValue = 0;
        int maxValue = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] >= 1) {
                if (counts[i] & 1) minValue++;
                maxValue += counts[i];
            }
        }
        minValue = max(1, minValue);
        if (k < minValue) return false;
        if (k > maxValue) return false;
        return true;
    }
};
