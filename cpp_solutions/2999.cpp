class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return numberOfPowerfulInt(to_string(finish), limit, s) - numberOfPowerfulInt(to_string(start - 1), limit, s);
    }
    long long numberOfPowerfulInt(string num, int limit, string s) {
        if (num.size() < s.size()) return 0;
        return dfs(num, limit, s, 0, true);
    }
    long long dfs(string num, int limit, string s, int index, bool isSame) {
        if (num.size() - index == s.size()) {
            if (!isSame || num.substr(index, s.size()) >= s) return 1;
            return 0;
        }
        if (!isSame) {
            return pow(limit + 1, num.size() - s.size() - index);
        }
        long long res = 0;
        for (int d = 0; d <= min(limit, num[index] - '0'); d++) {
            if (d == num[index] - '0') {
                res += dfs(num, limit, s, index + 1, true);
            }
            else {
                res += dfs(num, limit, s, index + 1, false);
            }
        }
        return res;
    }
};
