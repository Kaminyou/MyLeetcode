class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32, 0);
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        
        int res = 0;
        bool preBit = false;
        // from highest bit
        //     1[xxxxx] (# of i of x)
        // =>  0[?????] = f[i]
        // but 11[xxxx] can add 10[xxxx]
        // cannot 11_xxx so break
        for (int i = 30; i >= 0; --i) {
            if (n & (1 << i)) {
                res += f[i];
                if (preBit) return res;
                preBit = true;
            }
            else {
                preBit = false;
            }
        }
        // +1: n, because there is no consecutive 1
        // in n
        return res + 1;
    }
};