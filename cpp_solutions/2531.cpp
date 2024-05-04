class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> hashOne(26, 0);
        vector<int> hashTwo(26, 0);
        for (auto& c : word1) {
            hashOne[c - 'a']++;
        }
        for (auto& c : word2) {
            hashTwo[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (hashOne[i] <= 0) continue;
                if (hashTwo[j] <= 0) continue;
            
                // swap hashOne[i], hashTwo[j]
                hashOne[i]--;
                hashTwo[i]++;
                hashOne[j]++;
                hashTwo[j]--;
                
                
                int cnt1 = 0;
                int cnt2 = 0;
                for (int k = 0; k < 26; ++k) {
                    if (hashOne[k] > 0) cnt1++;
                    if (hashTwo[k] > 0) cnt2++;
                }
                if (cnt1 == cnt2) return true;
                hashOne[i]++;
                hashTwo[i]--;
                hashOne[j]--;
                hashTwo[j]++;
            }
        }
        return false;
    }
};