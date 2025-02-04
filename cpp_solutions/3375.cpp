class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (auto& num : nums) st.insert(num);
        int lower = 0;
        int higher = 0;
        for (auto& num : st) {
            if (num > k) higher++;
            if (num < k) lower++;
        }
        if (lower) return -1;
        return higher;
    }
};
