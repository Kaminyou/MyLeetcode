class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        vector<int> secretCount(10, 0);
        vector<int> guessCount(10, 0);
        int n = secret.size();
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) bull++;
            secretCount[secret[i] - '0']++;
            guessCount[guess[i] - '0']++;
        }
        int cow = 0;
        for (int i = 0; i < 10; ++i) {
            cow += min(secretCount[i], guessCount[i]);
        }
        cow -= bull;
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};