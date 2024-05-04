class Solution {
public:
    bool criteria(vector<int>& differences, int minSum, int partition) {
        // once >= minSum, make partition, the max partition can be made 
        int part = 0;
        int m = differences.size();
        int currSum = 0;
        for (int i = 0; i < m; ++i) {
            currSum += differences[i];
            if (currSum >= minSum) {
                part++;
                currSum = 0;
            }
        }
        return part < partition;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        vector<int> differences;
        int n = price.size();
        if (n == 1) return 0;
        for (int i = 0; i < n - 1; ++i) {
            differences.push_back(price[i + 1] - price[i]);
        }
        int left = 0;
        int right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(differences, mid, k - 1)) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};
