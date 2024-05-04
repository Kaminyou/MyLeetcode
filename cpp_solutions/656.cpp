class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();
        vector<int> paid(n, INT_MAX);
        vector<int> prev(n, -1);
        vector<int> counts(n, 0);
        paid[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (coins[i] == -1) continue;
            for (int j = max(0, i - maxJump); j < i; ++j) {
                if (paid[j] == INT_MAX) continue;
                int newPaid = paid[j] + coins[i];
                if (newPaid < paid[i] || (newPaid == paid[i] && counts[i] < counts[j] + 1)) {
                    paid[i] = newPaid;
                    prev[i] = j;
                    counts[i] = counts[j] + 1;
                }
            }
        }
        if (paid[n - 1] == INT_MAX) return {};
        vector<int> res;
        for (int curr = n - 1; curr != -1; curr = prev[curr]) {
            res.push_back(curr + 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
