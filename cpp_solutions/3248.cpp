class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0;
        int y = 0;
        for (auto& command : commands) {
            if (command == "UP") y--;
            else if (command == "DOWN") y++;
            else if (command == "RIGHT") x++;
            else if (command == "LEFT") x--;
        }
        return y * n + x;
    }
};
