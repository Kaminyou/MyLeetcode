class Solution {
public:
    bool isPowerOfThree(int n) {
        int left = 0;
        int right = 20;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (pow(3, mid) >= n) right = mid;
            else left = mid + 1;
        }
        if (pow(3, left) == n) return true;
        return false;
    }
};