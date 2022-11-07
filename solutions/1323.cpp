class Solution {
public:
    int maximum69Number (int num) {
        int target = -1;
        int index = 0;
        int copyNum = num;
        while (copyNum) {
            int digit = copyNum % 10;
            if (digit == 6) target = max(target, index);
            copyNum /= 10;
            index++;
        }
        if (target == -1) return num;
        num -= 6 * pow(10, target);
        num += 9 * pow(10, target);
        return num;
    }
};