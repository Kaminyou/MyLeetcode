class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long current = 0;
        long long maxValue = 0;
        long long minValue = 0;
        for (auto& difference: differences) {
            current = current + difference;
            maxValue = max(maxValue, current);
            minValue = min(minValue, current);
        }
        long long range = maxValue - minValue + 1;
        long long res = upper - lower - range + 2;
        return max(0, (int)res);
    }
};
