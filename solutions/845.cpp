class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        int up = 0;
        int down = 0;
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            if (down && arr[i - 1] < arr[i] || arr[i - 1] == arr[i]) {
                up = down = 0;
            }
            if (arr[i - 1] < arr[i]) up++;
            if (arr[i - 1] > arr[i]) down++;
            if (up && down) res = max(res, up + down + 1);
        }
        return res;
    }
};