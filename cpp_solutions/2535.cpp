class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int digitSum = 0;
        for (auto num : nums) {
            elementSum += num;
            while (num) {
                int digit = num % 10;
                digitSum += digit;
                num /= 10;
            }
        }
        return abs(elementSum - digitSum);
    }
};