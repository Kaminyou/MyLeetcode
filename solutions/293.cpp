class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        int n = currentState.size();
        if (n == 1) return res;
        for (int i = 0; i <= n - 2; ++i) {
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                currentState[i] = '-';
                currentState[i + 1] = '-';
                res.push_back(currentState);
                currentState[i] = '+';
                currentState[i + 1] = '+';
            }
        }
        return res;
    }
};