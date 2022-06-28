class Solution {
public:
    bool canTransform(string start, string end) {
        int startR = 0;
        int startL = 0;
        int startX = 0;
        int endR = 0;
        int endL = 0;
        int endX = 0;
        string startClean = "";
        string endClean = "";
        int n = start.size();
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'R') {
                startR++;
                startClean.push_back('R');
            }
            else if (start[i] == 'L') {
                startL++;
                startClean.push_back('L');
            }
            else if (start[i] == 'X') startX++;
            if (end[i] == 'R') {
                endR++;
                endClean.push_back('R');
            }
            else if (end[i] == 'L') {
                endL++;
                endClean.push_back('L');
            }
            else if (end[i] == 'X') endX++;
            if (endR > startR) return false;
            if (endL < startL) return false;
        }
        if (startR != endR || startL != endL || startX != endX) return false;
        if (startClean != endClean) return false;
        return true;
    }
};