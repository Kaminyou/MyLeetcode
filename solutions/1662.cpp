class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int wordIdx1 = 0;
        int wordIdx2 = 0;
        int idx1 = 0;
        int idx2 = 0;
        while (wordIdx1 < word1.size() && wordIdx2 < word2.size()) {
            while (wordIdx1 < word1.size() && idx1 == word1[wordIdx1].size()) {
                idx1 = 0;
                wordIdx1++;
            }
            while (wordIdx2 < word2.size() && idx2 == word2[wordIdx2].size()) {
                idx2 = 0;
                wordIdx2++;
            }
            if (wordIdx1 == word1.size() && wordIdx2 == word2.size()) return true;
            if (wordIdx1 == word1.size() || wordIdx2 == word2.size()) return false;
            if (word1[wordIdx1][idx1] != word2[wordIdx2][idx2]) return false;
            idx1++;
            idx2++;
        }
        return wordIdx1 == word1.size() && wordIdx2 == word2.size();
    }
};