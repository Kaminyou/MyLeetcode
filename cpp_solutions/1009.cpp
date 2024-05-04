class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        uint size = log2(n) + 1;
        uint mask = (1 << size) - 1;
        return n ^ mask;
    }
};