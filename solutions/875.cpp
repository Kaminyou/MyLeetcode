class Solution {
public:
    bool criteria(vector<int>& piles, int speed, int h) {
        long long time = 0;
        for (auto& pile : piles) {
            time += pile / speed;
            if (pile % speed) time += 1;
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(piles, mid, h)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};