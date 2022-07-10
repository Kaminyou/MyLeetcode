class Solution {
public:
    // dp[i][j]: if there are i unique values, how many unique sequences can be formed if the length is j
    vector<vector<long long>> dp;
    
    // prefixSum[i][j]: prefix sum for dp[i][:j]
    vector<vector<long long>> prefixSum;
    
    // choiceDp[i]: how many unique values "set" can be chosen when # of i unique values is required
    vector<long long> choiceDp;
    int n;
    int maxValue;
    long long mod = 1e9 + 7;
    
    // DFS, actually
    // add the current value to choiceDp[count]: count is the # of unique value
    // when the next value is less than maxValue
    // e.g., max = 7 and {curr->next} = 1 -> 2 or 2 -> 4 or 3 -> 6
    // we can add the next value to choiceDp[count + 1] => choiceDp[count]++
    void addChoice(int currentValue, int count) {
        choiceDp[count]++;
        for (int nextValue = currentValue * 2; nextValue <= maxValue; nextValue += currentValue) {
            addChoice(nextValue, count + 1);
        }
    }
    
    int idealArrays(int n, int maxValue) {
        this->n = n;
        this->maxValue = maxValue;
        // max unqiue values can be in the sequence is log2(maxValue) + 1
        // e.g., maxValue = 8 => [1,2,4,8] => log(8) + 1 = 4
        int maxUnique = static_cast<int>(log2(maxValue)) + 1;
        dp.resize(maxUnique + 1, vector<long long>(n + 1, 0));
        prefixSum.resize(maxUnique + 1, vector<long long>(n + 1, 0));
        choiceDp.resize(maxUnique + 1, 0);
        
        // Compute the # of unique sequences with i unique values and length = j
        // We don't care about what their values should be here
        // just [a,b,c,d] and a <= b <= c <= d
        for (int j = 1; j <= n; ++j) {
            dp[1][j] = 1;
            prefixSum[1][j] = j;
        }
        for (int i = 2; i <= maxUnique; ++i) {
            for (int j = i; j <= n; ++j) {
                // dp[i][j] = dp[i - 1][1] + dp[i - 1][2] + ... + dp[i - 1][j - 1]
                // use prefix sum to save time
                dp[i][j] = prefixSum[i - 1][j - 1];
                prefixSum[i][j] = prefixSum[i][j - 1] + dp[i][j];
                dp[i][j] %= mod;
                prefixSum[i][j] %= mod;
            }
        }
        
        // Compute the choice
        for (int j = 1; j <= maxValue; ++j) {
            addChoice(j, 1);
        }
        
        // Combine choice and unique sequences
        // e.g., [a,a,b,b] is one unique sequence with # of unique values = 2
        //       get the # of possible set of {a, b} and multiply
        long long res = 0;
        for (int i = 1; i <= maxUnique; ++i) {
            res += dp[i][n] * choiceDp[i];
            res %= mod;
        }
        return res;
    }
};