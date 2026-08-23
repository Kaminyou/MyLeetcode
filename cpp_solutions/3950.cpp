class Solution {
public:
    bool consecutiveSetBits(int n) {
        int setBit = 0b11;
        int cnt = 0;
        while (setBit <= n) {
            if ((n & setBit) == setBit) cnt++;
            setBit <<= 1;
        }
        return cnt == 1;
    }
};
