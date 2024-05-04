class Solution {
public:
    int calculate(vector<int>& turns) {
        int score = 0;
        int hasTen = 0;
        for (auto& turn : turns) {
            score += turn;
            if (hasTen > 0) score += turn;
            if (turn == 10) hasTen = 3;
            hasTen--;
            hasTen = max(hasTen, 0);
        }
        return score;
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = calculate(player1);
        int score2 = calculate(player2);
        if (score1 == score2) return 0;
        if (score1 > score2) return 1;
        return 2;
    }
};