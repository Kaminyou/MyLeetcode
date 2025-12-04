class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        int n = directions.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (directions[i] == 'R') cnt++;
            else {
                res += cnt;
                cnt = 0;
            }
        }
        cnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (directions[i] == 'L') cnt++;
            else {
                res += cnt;
                cnt = 0;
            }
        }
        return res;
    }
};
