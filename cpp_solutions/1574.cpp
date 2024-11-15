class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int j = n - 1;
        int res = n - 1;
        while (j >= 1 && arr[j] >= arr[j - 1]) j--;
        res = min(res, j);
        if (res == 0) return 0;

        for (int i = 0; i < n; ++i) {
            if (i >= 1 && arr[i] < arr[i - 1]) break;
            while (j < n && arr[i] > arr[j]) j++;
            res = min(res, j - i - 1);
        }
        return res;
    }
};
