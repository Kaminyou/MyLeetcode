class Solution {
public:
    int passThePillow(int n, int time) {
        int span = n * 2 - 2;
        time %= span;
        if (time <= (n - 1)) return time + 1;
        time -= (n - 1);
        return n - time;
    }
};