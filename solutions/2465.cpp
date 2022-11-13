class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<int> st;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            st.insert(sum);
            left++;
            right--;
        }
        return st.size();
    }
};