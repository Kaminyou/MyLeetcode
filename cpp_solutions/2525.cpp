class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false;
        bool heavy = false;
        long long vol = (long long)length * width * height;
        if ((length >= 1e4) || (width >= 1e4) || (height >= 1e4)) bulky = true;
        if (vol >= 1e9) bulky = true;
        if (mass >= 100) heavy = true;
        if (bulky && heavy) return "Both";
        if (!bulky && !heavy) return "Neither";
        if (!bulky && heavy) return "Heavy";
        return "Bulky";
    }
};