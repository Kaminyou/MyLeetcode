class Solution {
public:
    void backtracking(int* toUse, int now, int count, int& res, int n) {
        if (count >= 8) return;
        if (count == 0) {
            if (now > n) {
                res = min(res, now);
            }
            return;
        }
        for (int i = 1; i <= 7; ++i) {
            if (toUse[i] > 0) {
                toUse[i]--;
                now *= 10;
                now += i;
                count -= 1;
                backtracking(toUse, now, count, res, n);
                now /= 10;
                count += 1;
                toUse[i]++;
            }
        }
    }
    int nextBeautifulNumber(int n) {
        int res = INT_MAX;
        int toUse[8];
        for (int mask = 0; mask <= (1 << 7) - 1; ++mask) {
            int count = 0;
            for (int index = 0; index <= 6; ++index) {
                if (mask & (1 << index)) {
                    toUse[index + 1] = index + 1;
                    count += (index + 1);
                }
                else {
                    toUse[index + 1] = 0;
                }
            }
            backtracking(toUse, 0, count, res, n);
        }
        return res;
    }
};

