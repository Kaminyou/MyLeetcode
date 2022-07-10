class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sum = 0;
        int maxVal = 0;
        for (auto& num : amount) {
            sum += num;
            maxVal = max(maxVal, num);
        }
        return max(maxVal, (sum + 1) / 2);
    }
};