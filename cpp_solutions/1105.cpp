class Solution {
public:
    int dp(vector<int>& memo, vector<vector<int>>& books, vector<int>& prefixSum, vector<int>& prefixMax, int shelfWidth, int curr) {
        // [curr, n - 1]
        if (curr >= books.size()) return memo[curr] = 0;
        if (prefixSum[books.size()] - prefixSum[curr] <= shelfWidth) {
            return memo[curr] = prefixMax[curr];
        }
        if (memo[curr] != INT_MAX) return memo[curr];
        int currWidth = 0;
        int currMax = 0;
        for (int i = curr; currWidth + books[i][0] <= shelfWidth; i++) {
            currWidth += books[i][0];
            currMax = max(currMax, books[i][1]);
            memo[curr] = min(memo[curr], currMax + dp(memo, books, prefixSum, prefixMax, shelfWidth, i + 1));
        }
        return memo[curr];
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> memo(n, INT_MAX); // memo[i]: min height consider [i:n - 1]
        vector<int> prefixSum(n + 1, 0);
        vector<int> prefixMax(n, 0);
        for (int i = 0; i < n; ++i) prefixSum[i + 1] = prefixSum[i] + books[i][0];
        int maxVal = 0;
        for (int i = n - 1; i >= 0; --i) {
            maxVal = max(maxVal, books[i][1]);
            prefixMax[i] = maxVal;
        }
        int res = dp(memo, books, prefixSum, prefixMax, shelfWidth, 0);

        return res;
    }
};

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        books.insert(books.begin(), {0, 0});

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int maxHeight = 0;
            int width = 0;
            for (int j = i; j >= 1; --j) {
                maxHeight = max(maxHeight, books[j][1]);
                width += books[j][0];
                if (width > shelfWidth) break;
                dp[i] = min(dp[i], dp[j - 1] + maxHeight);
            }
        }
        return dp[n];
    }
};
