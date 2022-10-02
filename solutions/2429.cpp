class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2);
        int m = __builtin_popcount(num1);
        int res = 0;
        int index = 0;
        if (m > n) {
            vector<bool> v;
            while (num1 > 0) {
                if (num1 & 1) {
                    v.push_back(true);
                }
                else v.push_back(false);
                index++;
                num1 >>= 1;
            }
            int k = v.size() - 1;
            while (n > 0) {
                if (v[k] == true) {
                    res += (1 << k);
                    n--;
                }
                k--;
            }
            
            return res;
        }
        if (m == n) return num1;
        while (num1 && n > 0) {
            if (num1 & 1) {
                res += (1 << index);
                n--;
            }
            index++;
            num1 >>= 1;
        }
        index = 0;
        while (n > 0) {
            if ((((res & (1 << index)) >> index) & 1) == 0) {
                res += (1 << index);
                n--;
            }
            index++;
        }
        return res;
    }
};