class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        int index = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            if (st.find(nums[i]) != st.end()) {
                index = i;
                break;
            }
            st.insert(nums[i]);
        }
        // i + 1 okay
        if (index == INT_MAX) return 0;
        return index / 3 + 1;
    }
};
