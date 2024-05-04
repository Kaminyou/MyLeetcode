class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 1;
        int base = 1;
        int multi = 2;
        while (n - base >= multi) {
            if ((n - base) % multi == 0) res++;
            base += multi;
            multi++;
        }

        return res;
    }
};
