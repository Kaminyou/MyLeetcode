class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 1;
        while (res < INT_MAX / 2) {
            if (st.count(res)) {
                res *= 2;
            }
            else return res;
            
        }
        return res;
    }
};