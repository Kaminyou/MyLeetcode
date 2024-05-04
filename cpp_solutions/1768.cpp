class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int idx1 = 0;
        int idx2 = 0;
        string out;
        while (idx1 < m || idx2 < n) {
            if (idx1 < m) {
                out.push_back(word1[idx1]);
                idx1++;
            }
            if (idx2 < n) {
                out.push_back(word2[idx2]);
                idx2++;
            }
        }
        return out;
    }
};