class Solution {
public:
    string clear(string board) {
        int n = board.size();
        int index = 0;
        while (index < n) {
            char c = board[index];
            int start = index;
            while (index + 1 < n && board[index + 1] == c) index++;
            if (index - start + 1 >= 3) {
                string next = board.substr(0, start) + board.substr(index + 1);
                return clear(next);
            }
            index++;
        }
        return board;
    }
    int dfs(string board, vector<int>& counts, unordered_map<string, int>& memo) {
        if (board.size() == 0) return 0;
        string key = board + "#" + encodeFreq(counts);
        if (memo.find(key) != memo.end()) return memo[key];
        
        int n = board.size();
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                bool toTry = false;
                if (mapping(board[i]) == j) toTry = true;
                if (i > 0 && board[i] == board[i - 1] && mapping(board[i]) != j) toTry = true;
                
                if (counts[j] > 0 && toTry) {
                    board.insert(board.begin() + i, reverseMapping(j));
                    string next = clear(board);
                    counts[j]--;
                    int steps = dfs(next, counts, memo);
                    if (steps != INT_MAX) res = min(res, steps + 1);
                    counts[j]++;
                    board.erase(board.begin() + i);
                }
            }
        }
        memo[key] = res;
        return res;
    }
    int mapping(char c) {
        switch (c) {
            case 'R': 
                return 0;
            case 'Y':
                return 1;
            case 'B':
                return 2;
            case 'G':
                return 3;
            default:
                return 4;
        }
        return 4;
    }
    char reverseMapping(int i) {
        switch (i) {
            case 0: 
                return 'R';
            case 1:
                return 'Y';
            case 2:
                return 'B';
            case 3:
                return 'G';
            default:
                return 'W';
        }
        return 'W';
    }
    string encodeFreq(vector<int>& counts) {
        string res;
        for (int i = 0; i < 5; ++i) {
            res += to_string(counts[i]);
            res += "#";
        }
        return res;
    }
    int findMinStep(string board, string hand) {
        vector<int> counts(5, 0);
        for (auto c : hand) counts[mapping(c)]++;
        unordered_map<string, int> memo;
        
        int res = dfs(board, counts, memo);
        if (res == INT_MAX) return -1;
        return res;
    }
};