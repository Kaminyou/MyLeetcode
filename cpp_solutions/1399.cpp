class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int> counts(40, 0);
        int size = 0;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            counts[sum]++;
            if (counts[sum] == size) {
                cnt++;
            }
            else if (counts[sum] > size) {
                size = counts[sum];
                cnt = 1;
            }
        }
        return cnt;
    }
};
