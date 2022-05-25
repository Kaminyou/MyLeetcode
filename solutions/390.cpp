class Solution {
public:
    int lastRemaining(int n) {
        int step = 1;
        int head = 1;
        bool direction = true; // true: -> ; false: <-
        while (n > 1) {
            if (direction) {
                head += step;
            }
            else {
                if (n & 1) {
                    head += step;
                }
            }
            n /= 2;
            step *= 2;
            direction = !direction;
        }
        return head;
    }
};