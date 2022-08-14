class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        for (int i = 0; i < n; ++i) {
            nums[i] %= k;
        }
        
        unordered_set<int> st;
        int prevSum = 0;
        int currentSum = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                currentSum += nums[i];
            }
            if (i >= 1) {
                currentSum += nums[i];
                st.insert(prevSum % k);
                if (st.find(currentSum % k) != st.end()) return true;
                prevSum += nums[i - 1];
            }
        }
        return false;
    }
};