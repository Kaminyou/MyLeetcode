class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> st;
        int n = nums.size();
        
        int initLength = min(n, k + 1);
        for (int i = 0; i < n; ++i) {
            if (i > k) {
                st.erase(st.find(nums[i - k - 1]));
            }
            int current = nums[i];
            auto itLower = st.lower_bound(current);
            if (itLower != st.end()) {
                if (abs(*itLower - current) <= t) return true;
            }
            if (itLower != st.begin()) {
                itLower--;
                if (abs(*itLower - current) <= t) return true;
            }
            st.insert(current);
        }
        return false;
    }
};