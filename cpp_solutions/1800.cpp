class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int curr = 0;
        int sum = 0;
        for (auto& num : nums) {
            if (num <= curr) sum = num;
            else sum += num;
            curr = num;
            res = max(res, sum);
        }
        return res;
    }
};
