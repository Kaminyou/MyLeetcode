class Solution {
public:
    vector<pair<char, char>> strobogrammatics = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    string midStrobogrammatics = "018";
    vector<string> res;
    void backtracking(int n, int curr, string& forward, string& backward) {
        if (curr == n / 2) {
            reverse(backward.begin(), backward.end());
            if (n & 1) {
                for (auto& c : midStrobogrammatics) {
                    res.push_back(forward + c + backward);
                }
            }
            else {
                res.push_back(forward + backward);
            }
            reverse(backward.begin(), backward.end());
            return;
        }
        for (auto& strobogrammatic : strobogrammatics) {
            if (curr == 0 && strobogrammatic.first == '0') continue;
            forward.push_back(strobogrammatic.first);
            backward.push_back(strobogrammatic.second);
            backtracking(n, curr + 1, forward, backward);
            forward.pop_back();
            backward.pop_back();
        }
    }
    vector<string> findStrobogrammatic(int n) {
        string forward = "";
        string backward = "";
        backtracking(n, 0, forward, backward);
        return res;
    }
};