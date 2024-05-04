class Solution {
public:
    int findComplement(int num) {
        uint n = log2(num) + 1;
        uint mask = (uint)(1 << n) - 1;
        return num ^ mask;
    }
};