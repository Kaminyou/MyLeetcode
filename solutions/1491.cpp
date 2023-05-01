class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        double maxValue = INT_MIN;
        double minValue = INT_MAX;
        for (auto& element : salary) {
            sum += element;
            maxValue = max(maxValue, (double)element);
            minValue = min(minValue, (double)element);
        }
        return (sum - maxValue - minValue) / (salary.size() - 2);
    }
};