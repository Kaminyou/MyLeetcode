class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxH = 0;
        int maxV = 0;
        int index = 0;
        while (index < hBars.size()) {
            int left = index;
            while (index + 1 < hBars.size() && hBars[index] + 1 == hBars[index + 1]) index++;
            int length = index - left + 2;
            maxH = max(maxH, length);
            index++;
        }

        index = 0;
        while (index < vBars.size()) {
            int left = index;
            while (index + 1 < vBars.size() && vBars[index] + 1 == vBars[index + 1]) index++;
            int length = index - left + 2;
            maxV = max(maxV, length);
            index++;
        }
        int size = max(1, min(maxH, maxV));
        return size * size;
    }
};
