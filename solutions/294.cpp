class Solution {
public:
    unordered_map<string, bool> memo;
    bool win(string& currentState) {
        if (memo.find(currentState) != memo.end()) return memo[currentState];
        for (int i = 0; i < currentState.size() - 1; ++i) {
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                bool flag = false;
                currentState[i] = '-';
                currentState[i + 1] = '-';
                flag = !win(currentState);
                currentState[i] = '+';
                currentState[i + 1] = '+';
                if (flag) return memo[currentState] = true;
            }
        }
        return memo[currentState] = false;
    }
    bool canWin(string currentState) {
        return win(currentState);
    }
};