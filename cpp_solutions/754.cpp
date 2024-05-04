class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int k = 0;
        while (sum < target) {
            k++;
            sum += k;
        }
        int d = sum - target;
        if ((d & 1) == 0) return k;
        if (k & 1) return k + 2;
        return k + 1;
    }
};