class Solution {
public:
    int pivotInteger(int n) {
        int sum = (1 + n) * n / 2;
        for (int i = 1; i <= n; ++i) {
            int firstPart = (1 + i) * i / 2;
            int lastPart = sum - firstPart + i;
            if (firstPart == lastPart) return i;
        }
        return -1;
    }
};