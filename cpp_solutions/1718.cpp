class Solution {
public:
    vector<int> res;
    bool flag = false;
    bool backtracking(int n, int m, int mask, vector<int>& temp, int curr) {
        if (m == curr) {
            if (flag) return true;
            flag = true;
            res = temp;
            return true;
        }
        if (temp[curr] != -1) {
            bool o = backtracking(n, m, mask, temp, curr + 1);
            return o;
        }
        else {
            for (int i = n; i >= 1; --i) {
                if (mask & (1 << i)) {
                    continue;
                }
                if (i != 1 && curr + i >= m) continue;
                if (i != 1 && temp[curr + i] != -1) continue;
                temp[curr] = i;
                if (i != 1) temp[curr + i] = i;
                mask ^= (1 << i);
                bool o = backtracking(n, m, mask, temp, curr + 1);
                if (o) return true;
                mask ^= (1 << i);
                temp[curr] = -1;
                if (i != 1) temp[curr + i] = -1;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int m = (n - 1) * 2 + 1;
        vector<int> temp(m, -1);
        int mask = 0;
        backtracking(n, m, mask, temp, 0);
        return res;
    }
};

