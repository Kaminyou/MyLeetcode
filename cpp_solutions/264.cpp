class Solution {
public:
    int nthUglyNumber(int n) {
        int indexTwo = 0;
        int indexThree = 0;
        int indexFive = 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int numTwo = dp[indexTwo] * 2;
            int numThree = dp[indexThree] * 3;
            int numFive = dp[indexFive] * 5;
            int minValue = min({numTwo, numThree, numFive});
            dp[i] = minValue;
            
            if (minValue == numTwo) indexTwo++;
            if (minValue == numThree) indexThree++;
            if (minValue == numFive) indexFive++;
        }
        return dp[n - 1];
    }
};

