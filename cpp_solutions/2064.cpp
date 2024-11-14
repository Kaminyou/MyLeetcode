class Solution {
public:
    bool valid(int num, int n, vector<int>& quantities) {
        for (auto quantity : quantities) {
            int cnt = ((quantity - 1) / num) + 1;
            n -= cnt;
            if (n < 0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(mid, n, quantities)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
