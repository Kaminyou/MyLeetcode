class Solution {
public:
    bool canChange(string start, string target) {
        int startL = 0;
        int startR = 0;
        int startEmpty = 0;
        int targetL = 0;
        int targetR = 0;
        int targetEmpty = 0;
        int n = start.size();
        
        string startClean = "";
        string targetClean = "";
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'L') {
                startL++;
                startClean.push_back('L');
            }
            else if (start[i] == 'R') {
                startR++;
                startClean.push_back('R');
            }
            else if (start[i] == ' ') startEmpty++;
            
            if (target[i] == 'L') {
                targetClean.push_back('L');
                targetL++;
            }
            else if (target[i] == 'R') {
                targetR++;
                targetClean.push_back('R');
            }
            else if (target[i] == ' ') targetEmpty++;
            
            if (startL > targetL) return false;
            if (startR < targetR) return false;
        }
        if (startL != targetL) return false;
        if (startR != targetR) return false;
        if (startEmpty != targetEmpty) return false;
        if (startClean != targetClean) return false;
        return true;
    }
};