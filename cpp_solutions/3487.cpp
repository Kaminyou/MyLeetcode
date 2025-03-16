class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int res = 0;
        int used = 0;
        int maxVal = INT_MIN;
        for (auto& num : nums) {
            maxVal = max(maxVal, num);
            if (num > 0) {
                if (!st.count(num)) {
                    res += num;
                    st.insert(num);
                    used += 1;
                }
            }
        }
        if (used == 0) {
            return maxVal;
        }
        return res;
    }
};
