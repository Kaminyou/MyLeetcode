class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        unordered_set<int> st;
        int res = 0;
        for (auto& num : nums) {
            if (st.find(num - diff) != st.end() && st.find(num - 2 * diff) != st.end()) res++;
            st.insert(num);
        }
        return res;
    }
};