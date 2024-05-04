class Solution {
public:
    int numWays(int n, int k) {
        int same = 0;
        int diff = k;
        for (int i = 2; i <= n; ++i) {
            int temp = diff;
            diff = (same + diff) * (k - 1);
            same = temp;
        }
        return same + diff;
    }
};