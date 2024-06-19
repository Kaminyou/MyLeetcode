class Solution {
public:
    bool criteria(vector<int>& bloomDay, int m, int k, int days) {
        int n = bloomDay.size();
        int tempCnt = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] <= days) {
                tempCnt += 1;
            }
            else {
                tempCnt = 0;
            }
            if (tempCnt == k) {
                cnt += 1;
                tempCnt = 0;
            }
        }
        return cnt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > (long long)n) return -1;
        int left = 0;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(bloomDay, m, k, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

