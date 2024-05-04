class Solution {
public:
    bool checkPerfectNumber(int num) {
        int upperBound = sqrt(num);
        int sum = 0;
        for (int i = 1; i <= upperBound; ++i) {
            if (num % i == 0) {
                int j = num / i;
                if (i != num) sum += i;
                if (j != i && j != num) sum += j;
            }
        }
        return sum == num;
    }
};