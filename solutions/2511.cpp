class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        vector<int> fromLeft(n, INT_MIN / 2);
        vector<int> fromRight(n, INT_MIN / 2);
        if (forts[0] == -1) fromLeft[0] = 0;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (forts[i] == -1) fromLeft[i] = 0;
            else if (forts[i] == 0) fromLeft[i] = fromLeft[i - 1] + 1;
            else {
                ans = max(ans, fromLeft[i - 1]);
                fromLeft[i] = INT_MIN / 2;
            }
        }
        
        if (forts[n - 1] == -1) fromRight[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (forts[i] == -1) fromRight[i] = 0;
            else if (forts[i] == 0) fromRight[i] = fromRight[i + 1] + 1;
            else {
                ans = max(ans, fromRight[i + 1]);
                fromRight[i] = INT_MIN / 2;
            }
        }
        return ans;
    }
};