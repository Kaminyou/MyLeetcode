class Solution {
public:
    bool winnerOfGame(string colors) {
        int cntA = 0;
        int cntB = 0;
        int n = colors.size();
        int index = 0;
        while (index < n) {
            int start = index;
            char c = colors[index];
            while (index + 1 < n && colors[index + 1] == c) index++;
            if (c == 'A') {
                cntA += max(0, index - start - 1);
            }
            if (c == 'B') {
                cntB += max(0, index - start - 1);
            }
            index++;
        }
        return cntA > cntB;
    }
};
