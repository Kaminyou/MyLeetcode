class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                index++;
            }
            else break;
        }
        int sum = 0;
        for (int i = 0; i <= index; ++i) {
            sum += nums[i];
        }
        unordered_set<int> st(nums.begin(), nums.end());
        for (int i = 0; i <= n; ++i) {
            if (!st.count(sum + i)) return sum + i;
        }
        return -1;
    }
};
