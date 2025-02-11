class Solution {
public:
    bool canAliceWin(int n) {
        int curr = 10;
        while (true) {
            if (n < curr) return false;
            n -= curr;
            curr--;
            if (n < curr) return true;
            n -= curr;
            curr--;
        }
        return true;
    }
};
