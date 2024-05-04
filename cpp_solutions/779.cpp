class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        if (n == 2) {
            if (k == 1) return 0;
            else return 1;
        }
        if (k > (1 << (n - 2))) {
            return 1 ^ kthGrammar(n - 1, (k - 1) % (1 << (n - 2)) + 1);
        }
        return kthGrammar(n - 1, k);
    }
};
