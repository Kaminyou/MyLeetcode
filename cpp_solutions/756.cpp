class Solution {
public:
    unordered_map<string, bool> memo;
    unordered_map<string, vector<char>> bottom2top;
    void generate(string& bottom, int position, string& currentString, vector<string>& strings) {
        if (position == bottom.size() - 1) {
            strings.push_back(currentString);
            return;
        }
        string current = bottom.substr(position, 2);
        for (auto c : bottom2top[current]) {
            currentString.push_back(c);
            generate(bottom, position + 1, currentString, strings);
            currentString.pop_back();
        }
    }
    bool backtracking(string& bottom) {
        if (bottom.size() == 1) return true;
        if (memo.find(bottom) != memo.end()) return memo[bottom];
        vector<string> availables;
        string currentString;
        generate(bottom, 0, currentString, availables);
        for (auto available : availables) {
            if (backtracking(available)) return memo[bottom] = true;
        }
        return memo[bottom] = false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& allow : allowed) {
            bottom2top[allow.substr(0, 2)].push_back(allow[2]);
        }
        return backtracking(bottom);
    }
};