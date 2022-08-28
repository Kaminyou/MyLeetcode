class Solution {
public:
    int flipLights(int n, int presses) {
        if (n == 0 || presses == 0) return 1;
        
        if (n == 1 && presses == 1) return 2;
        if (n == 1 && presses == 2) return 2;
        if (n == 1 && presses >= 3) return 2;
        
        if (n == 2 && presses == 1) return 3;
        if (n == 2 && presses >= 2) return 4;
        
        if (n >= 3 && presses > 2) return 8;
        if (n >= 3 && presses == 2) return 7;
        if (n >= 3 && presses == 1) return 4;
        return -1;
    }
};
// 1 + 2 = 3
// 1 + 3 = 2
// 2 + 3 = 1