class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        vector<vector<int>> badTransactions;
        long long res = 0;
        long long sum = 0;
        long long maxBegin = 0;
        for (auto& transaction : transactions) {
            res = max(res, (long long)transaction[0]);
            if ((long long)transaction[1] - (long long)transaction[0] >= 0) {
                maxBegin = max(maxBegin, (long long)transaction[0]);
                continue;
            }
            badTransactions.push_back(transaction);
            sum += (long long)transaction[0] - (long long)transaction[1];
        }
        res = max(res, sum + maxBegin);
        for (auto& transaction : badTransactions) {
            res = max(res, sum - ((long long)transaction[0] - (long long)transaction[1]) + (long long)transaction[0]);
        }
        return res;
    }
};
