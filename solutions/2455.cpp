class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        for (auto& num : nums) {
            if (num & 1) continue;
            if (num % 3 != 0) continue;
            sum += num;
            count++;
        }
        if (count == 0) return 0;
        return sum / count;
    }
};