class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int res = 0;
        int curr = 0;
        for (int i = 0; i < k; ++i) {
            curr *= 10;
            curr += 1;
            curr %= k;
            if (curr == 0) return i + 1;
        }
        return -1;
    }
};

