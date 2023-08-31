class Solution {
public:
    static bool cmp(array<int, 2>& a, array<int, 2>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<array<int, 2>> sortedRanges(n + 1);
        for (int i = 0; i <= n; ++i) {
            sortedRanges[i] = {i - ranges[i], i + ranges[i]};
        }
        sort(sortedRanges.begin(), sortedRanges.end(), cmp);

        int index = 0;
        int count = 0;
        int far = 0;
        while (index <= n) {
            int nextFar = far;
            while (index <= n && sortedRanges[index][0] <= far) {
                nextFar = max(nextFar, sortedRanges[index][1]);
                index++;
            }
            count++;
            if (nextFar >= n) return count;
            if (nextFar == far) return -1;
            far = nextFar;
        }
        return -1;
    }
};
