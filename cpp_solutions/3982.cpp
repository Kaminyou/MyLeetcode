class Solution {
public:
    int getRange(int num) {
        int minV = 10;
        int maxV = -1;
        while (num) {
            int digit = num % 10;
            minV = min(minV, digit);
            maxV = max(maxV, digit);
            num /= 10;
        }
        return maxV - minV;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxRange = 0;
        for (auto& num : nums) {
            int range = getRange(num);
            maxRange = max(maxRange, range);
        }
        int res = 0;
        for (auto& num : nums) {
            int range = getRange(num);
            if (range == maxRange) res += num;
        }
        return res;
    }
};
