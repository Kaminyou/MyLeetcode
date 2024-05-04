class Solution {
public:
    long long mod = 1e9 + 7;
    int getDigitSum(string& num) {
        int sum = 0;
        for (auto c : num) {
            sum += (c - '0');
        }
        return sum;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        long long res = (countWithLimit(num2, max_sum) - countWithLimit(num2, min_sum - 1)) - (countWithLimit(num1, max_sum) - countWithLimit(num1, min_sum - 1));
        if (getDigitSum(num1) >= min_sum && getDigitSum(num1) <= max_sum) res++;
        res += mod * 2;
        res %= mod;
        return res;
    }
    long long countWithLimit(string& num, int maxSum) {
        vector<vector<vector<long long>>> memo(2, vector<vector<long long>>(24, vector<long long>(405, -1)));
        return dfs(num, maxSum, 0, 0, true, memo);
    }
    long long dfs(string& num, int maxSum, int idx, int digitSum, bool isSame, vector<vector<vector<long long>>>& memo) {
        if (digitSum > maxSum) return 0;
        if (memo[isSame][idx][digitSum] != -1) return memo[isSame][idx][digitSum];
        if (idx == num.size()) return 1;
        long long res = 0;
        if (isSame) {
            int target = num[idx] - '0';
            for (int i = 0; i < target; ++i) {
                res += dfs(num, maxSum, idx + 1, digitSum + i, false, memo);
                res %= mod;
            }
            res += dfs(num, maxSum, idx + 1, digitSum + target, true, memo);
            res %= mod;
        }
        else {
            for (int i = 0; i <= 9; ++i) {
                res += dfs(num, maxSum, idx + 1, digitSum + i, false, memo);
                res %= mod;
            }
        }
        res %= mod;
        memo[isSame][idx][digitSum] = res;
        return res;
    }
};
