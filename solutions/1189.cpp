class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> counts(5, 0); // a, b, l, n, o
        vector<int> div = {1, 1, 2, 1, 2};
        for (auto c : text) {
            if (c == 'a') counts[0]++;
            else if (c == 'b') counts[1]++;
            else if (c == 'l') counts[2]++;
            else if (c == 'n') counts[3]++;
            else if (c == 'o') counts[4]++;
        }
        int res = INT_MAX;
        for (int i = 0; i < 5; ++i) {
            res = min(res, counts[i] / div[i]);
        }
        return res;
    }
};