/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int left = 0;
        int right = 1;
        while (left < n && right < n) {
            if (!knows(left, right)) {
                right++;
            }
            else {
                left = right;
                right++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == left) continue;
            if (!knows(i, left)) return -1;
            if (knows(left, i)) return -1;
        }
        return left;
    }
};