class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> firstPart = {0};
        vector<int> secondPart = {0};
        firstPart.reserve(1 << (n / 2 + 1));
        secondPart.reserve(1 << (n / 2 + 1));
        for (int i = 0; i < n / 2; ++i) {
            int m = firstPart.size();
            for (int j = 0; j < m; ++j) firstPart.push_back(nums[i] + firstPart[j]);
        }
        
        for (int i = n / 2; i < n; ++i) {
            int m = secondPart.size();
            for (int j = 0; j < m; ++j) secondPart.push_back(nums[i] + secondPart[j]);
        }
        
        unordered_set<int> queries(firstPart.begin(), firstPart.end());
        set<int> st(secondPart.begin(), secondPart.end());
        
        int res = abs(goal);
        for (auto& query : queries) {
            int target = goal - query;
            
            auto it = st.lower_bound(target);
            if (it != st.end()) res = min(res, abs(goal - (query + *it)));
            if (it != st.begin()) res = min(res, abs(goal - (query + *(prev(it)))));
        }
        return res;
    }
};