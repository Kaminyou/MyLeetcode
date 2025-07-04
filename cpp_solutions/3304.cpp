class Solution {
public:
    char kthCharacter(int k) {
        int ops = 0;
        while (k > 1) {
            int now = 1;
            while ((now << 1) < k) now <<= 1;
            ops++;
            k -= now;
        }
        return (ops % 26) + 'a';
    }
};
