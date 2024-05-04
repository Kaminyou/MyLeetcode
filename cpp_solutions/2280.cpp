class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() <= 1) return 0;
        int count = 1;
        sort(stockPrices.begin(), stockPrices.end());
        for (int i = 1; i < stockPrices.size() - 1; ++i) {
            long long x1 = stockPrices[i - 1][0];
            long long y1 = stockPrices[i - 1][1];
            
            long long x2 = stockPrices[i][0];
            long long y2 = stockPrices[i][1];
            
            long long x3 = stockPrices[i + 1][0];
            long long y3 = stockPrices[i + 1][1];
            
            long long a = (x2 - x1) * (y3 - y2);
            long long b = (x3 - x2) * (y2 - y1);
            if (a != b) count++;
        }
        return count;
    }
};