class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int midElement = nums[n / 2];
        int cnt = 0;
        for (auto& num : nums) {
            if (num == midElement) cnt++;
        }
        return cnt == 1;
    }
};
