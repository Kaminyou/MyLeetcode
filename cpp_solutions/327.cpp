class Solution {
public:
    int mergeSort(vector<long long>& prefixSum, int left, int right, int lower, int upper) {
        if (left > right) return 0;
        if (left == right) return (prefixSum[left] <= upper && prefixSum[left] >= lower) ? 1 : 0;
        vector<long long> temp(right - left + 1, 0);
        int res = 0;
        int mid = left + (right - left) / 2;
        res += (mergeSort(prefixSum, left, mid, lower, upper) + mergeSort(prefixSum, mid + 1, right, lower, upper));
        
        int i, j, k;
        for (i = left, j = k = mid + 1; i <= mid; i++) {
            while (j <= right && prefixSum[j] - prefixSum[i] < lower) j++;
            while (k <= right && prefixSum[k] - prefixSum[i] <= upper) k++;
            res += (k - j);
        }
        for (i = k = left, j = mid + 1; k <= right; k++) {
            temp[k - left] = (i <= mid) && (j > right || prefixSum[i] < prefixSum[j]) ? prefixSum[i++] : prefixSum[j++];
        }
        for (int i = 0; i < temp.size(); i++) {
            prefixSum[left + i] = temp[i];
        }
        return res;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return mergeSort(prefixSum, 1, n, lower, upper);
    }
};