class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL = 0;
        int cntR = 0;
        int cntE = 0;
        for (auto& move : moves) {
            if (move == 'L') cntL++;
            else if (move == 'R') cntR++;
            else cntE++;
        }
        return abs(cntL - cntR) + cntE;
    }
};
