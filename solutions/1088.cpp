class Solution {
public:
    vector<pair<int, int>> pairs = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
    vector<long long> power = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
    int res = 0;
    void backtracking(int n, int curr, long long currInt, long long reverseInt) {
        if (currInt > n) return;
        if (currInt >= 1 && currInt <= n) {
            if (currInt != reverseInt) {
                res++;
            }
        }
        for (auto& [f, r] : pairs) {
            if (curr == 0 && f == 0) continue;
            backtracking(n, curr + 1, currInt * 10 + f, reverseInt + r * power[curr]);
        }
    }
    int confusingNumberII(int n) {
        long long currInt = 0;
        long long reverseInt = 0;
        backtracking(n, 0, currInt, reverseInt);
        return res;
    }
};