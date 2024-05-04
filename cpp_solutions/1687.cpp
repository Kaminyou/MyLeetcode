class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        int right = 0;
        int lastRight = 0;
        int need = 0;
        for (int left = 0; left < n; ++left) {
            
            while (right < n && maxBoxes > 0 && boxes[right][1] <= maxWeight) {
                maxBoxes--;
                maxWeight -= boxes[right][1];
                if (right == 0 || boxes[right][0] != boxes[right - 1][0]) {
                    need++;
                    lastRight = right;
                }
                right++;
            }
            dp[right] = min(dp[right], dp[left] + need + 1);
            dp[lastRight] = min(dp[lastRight], dp[left] + need);
            
            maxBoxes++;
            maxWeight += boxes[left][1];
            if (left == n - 1 || boxes[left][0] != boxes[left + 1][0]) {
                need--;
            }
        }
        return dp[n];
    }
};