class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        int maxVal = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] < maxVal) {
                cnt++;
            }
            else{
                maxVal = arr[i];
                cnt = 1;
            }
            if (cnt == k) return maxVal;
        }
        return maxVal;
    }
};
