class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<pair<int, int>> char2position(26);
        int index = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                char2position[index] = {i, j};
                index++;
            }
        }
        char2position[index] = {5, 0};
        
        
        int x = 0;
        int y = 0;
        char current = 'a';
        string res;
        for (auto& c : target) {
            if (current == c) {
                res.push_back('!');
                continue;
            }
            // current -> c;
            auto [nextX, nextY] = char2position[c - 'a'];
            if (current == 'z') {
                // up and right
                for (int i = 0; i < (x - nextX); ++i) res.push_back('U');
                for (int i = 0; i < (nextY - y); ++i) res.push_back('R');
            }
            else if (c == 'z') {
                // left and down
                for (int i = 0; i < (y - nextY); ++i) res.push_back('L');
                for (int i = 0; i < (nextX - x); ++i) res.push_back('D');
            }
            else {
                int dx = x - nextX;
                if (dx > 0) {
                    for (int i = 0; i < dx; ++i) res.push_back('U');
                }
                else {
                    for (int i = 0; i < -dx; ++i) res.push_back('D');
                }
                int dy = y - nextY;
                if (dy > 0) {
                    for (int i = 0; i < dy; ++i) res.push_back('L');
                }
                else {
                    for (int i = 0; i < -dy; ++i) res.push_back('R');
                }
            }
            res.push_back('!');
            x = nextX;
            y = nextY;
            current = c;
        }
        return res;
    }
};