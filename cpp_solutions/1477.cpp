class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum = 0;
        int left = 0;
        int ans = INT_MAX;
        vector<int> minLenRecord(arr.size(), INT_MAX);
        int minLen = INT_MAX;
        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                if (left > 0 && minLenRecord[left - 1] != INT_MAX) {
                    ans = min(ans, right - left + 1 + minLenRecord[left - 1]);
                }
                minLen = min(minLen, right - left + 1);
                sum -= arr[left];
                left++;
            }
            minLenRecord[right] = minLen;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
