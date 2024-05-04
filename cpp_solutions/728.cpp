class Solution {
public:
    bool isSelfDivided(int num) {
        int temp = num;
        while (temp) {
            int digit = temp % 10;
            if (digit == 0) return false;
            if (num % digit != 0) return false;
            temp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int num = left; num <= right; ++num) {
            if (isSelfDivided(num)) res.push_back(num);
        }
        return res;
    }
};