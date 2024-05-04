class Solution {
public:
    int maxScore = 0;
    void backtracking(vector<string>& words, int currentIdx, int currentScore, vector<int>& count, vector<int>& score) {
        int n = words.size();
        for (int i = 0; i < 26; ++i) {
            if (count[i] < 0) return;
        }
        maxScore = max(maxScore, currentScore);
        for (int i = currentIdx; i < n; ++i) {
            int accum = 0;
            for (auto& c : words[i]) {
                count[c - 'a']--;
                accum += score[c - 'a'];
            }
            backtracking(words, i + 1, currentScore + accum, count, score);
            for (auto& c : words[i]) {
                count[c - 'a']++;
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        for (auto& c : letters) count[c - 'a']++;
        backtracking(words, 0, 0, count, score);
        return maxScore;
    }
};