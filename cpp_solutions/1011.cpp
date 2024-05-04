class Solution {
public:
    bool criteria(vector<int>& weights, int capacity, int days) {
        int current = 0;
        int count = 1;
        for (auto& weight : weights) {
            current += weight;
            if (current > capacity) {
                current = weight;
                count += 1;
            }
        }
        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int minValue = INT_MIN;
        int sum = 0;
        for (auto& weight : weights) {
            minValue = max(minValue, weight);
            sum += weight;
        }
        int left = minValue;
        int right = sum;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(weights, mid, days)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};