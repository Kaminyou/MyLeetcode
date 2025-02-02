class Solution {
public:
    int _maxDistance(string& s, int k, char targetX, char targetY) {
        int res = 0;
        int x = 0;
        int y = 0;
        for (auto& c : s) {
            if (c == 'N' || c == 'S') {
                if (c == targetX) x++;
                else {
                    if (k) {
                        k--;
                        x++;
                    }
                    else {
                        x--;
                    }
                }
            }
            
            if (c == 'E' || c == 'W') {
                if (c == targetY) y++;
                else {
                    if (k) {
                        k--;
                        y++;
                    }
                    else {
                        y--;
                    }
                }
            }
            res = max(res, abs(x) + abs(y));
        }
        return res;
    }
    int maxDistance(string s, int k) {
        int res = 0;
        res = max(res, _maxDistance(s, k, 'N', 'W'));
        res = max(res, _maxDistance(s, k, 'N', 'E'));
        res = max(res, _maxDistance(s, k, 'S', 'W'));
        res = max(res, _maxDistance(s, k, 'S', 'E'));
        return res;
    }
};

