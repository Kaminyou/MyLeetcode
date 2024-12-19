class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxVal = -1;
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxVal = max(arr[i], maxVal);
            if (maxVal == i) res++;
        }
        return res;
    }
};
