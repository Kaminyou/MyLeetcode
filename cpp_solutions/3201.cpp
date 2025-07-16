class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int endOdd = 0;
        int endEven = 0;
        int allOdd = 0;
        int allEven = 0;
        for (auto& num : nums) {
            if (num & 1) {
                allOdd++;
                endOdd = endEven + 1;
            }
            else {
                allEven++;
                endEven = endOdd + 1;
            }
        }
        return max({endOdd, endEven, allOdd, allEven});
    }
};

