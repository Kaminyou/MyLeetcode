class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int oneCnt = 0;
        int n = arr.size();
        for (auto& bit : arr) {
            if (bit & 1) oneCnt++;
        }
        if (oneCnt == 0) return {0, n - 1};
        if (oneCnt % 3 != 0) return {-1, -1};
        
        int target = oneCnt / 3;
        int firstIdx = -1; // first 1 [1, k]
        int secondIdx = -1; // k + 1 [k + 1, 2k]
        int thirdIdx = -1; // 2k + 1 [2K + 1, 3k]
        oneCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] & 1) oneCnt++;
            if (oneCnt == 1 && firstIdx == -1) firstIdx = i;
            else if (oneCnt == target + 1 && secondIdx == -1) secondIdx = i;
            else if (oneCnt == 2 * target + 1) {
                thirdIdx = i;
                break;
            }
        }
        // check each partition
        while (thirdIdx < n) {
            if (arr[firstIdx] == arr[secondIdx] && arr[secondIdx] == arr[thirdIdx]) {
                firstIdx++;
                secondIdx++;
                thirdIdx++;
            }
            else break;
        }
        if (thirdIdx != n) return {-1, -1};
        return {firstIdx - 1, secondIdx};
    }
};