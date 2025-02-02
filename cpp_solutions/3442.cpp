class Solution {
public:
    int maxDifference(string s) {
        vector<int> freqs(26, 0);
        for (auto& c : s) {
            freqs[c - 'a']++;
        }
        int maxFreq = 0;
        int minFreq = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (freqs[i] & 1) {
                maxFreq = max(maxFreq, freqs[i]);
            }
            else if (freqs[i] != 0) {
                minFreq = min(minFreq, freqs[i]);
            }
        }
        return maxFreq - minFreq;
    }
};
