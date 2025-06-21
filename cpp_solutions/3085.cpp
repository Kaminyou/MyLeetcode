class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freqs(26, 0);
        for (auto& c : word) {
            freqs[c - 'a']++;
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (freqs[i] == 0) continue;
            int minFreq = freqs[i];
            int maxFreq = minFreq + k;
            int cnt = 0;
            for (int j = 0; j < 26; ++j) {
                if (freqs[j] == 0) continue;
                if (freqs[j] > maxFreq) cnt += (freqs[j] - maxFreq);
                if (freqs[j] < minFreq) cnt += freqs[j];
            }
            res = min(res, cnt);
        }
        return res;
    }
};

