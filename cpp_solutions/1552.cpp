class Solution {
public:
    bool criteria(vector<int>& position, int m, int interval) {
        int n = position.size();
        int current = INT_MIN;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (position[i] >= current + interval) {
                current = position[i];
                cnt += 1;
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 0;
        int right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!criteria(position, m, mid)) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};

