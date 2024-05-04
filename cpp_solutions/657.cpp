class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0;
        int horizonal = 0;
        for (auto c : moves) {
            if (c == 'R') horizonal++;
            else if (c == 'L') horizonal--;
            else if (c == 'U') vertical++;
            else vertical--;
        }        
        return !vertical && !horizonal;
    }
};