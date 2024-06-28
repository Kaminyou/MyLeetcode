class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (auto& num : nums) {
            int m = num % 3;
            res += min(m, 3 - m);
        }
        return res;
    }
};
