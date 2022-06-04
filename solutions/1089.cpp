class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int j = n + count(arr.begin(), arr.end(), 0);
        
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n) {
                arr[j] = arr[i];
            }
            if (arr[i] == 0 && --j < n) {
                arr[j] = 0;
            }
        }
    }
};