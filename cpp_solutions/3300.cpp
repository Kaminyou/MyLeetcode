class Solution {
public:
    int calculate(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (auto& num : nums) {
            res = min(res, calculate(num));
        }
        return res;
    }
};
