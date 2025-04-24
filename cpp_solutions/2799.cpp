class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int diff = st.size();
        int res = 0;
        int right = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        int currentDiff = 0;

        // [left, right]
        for (int left = 0; left < n; ++left) {
            while (currentDiff < diff && right < n) {
                mp[nums[right]]++;
                if (mp[nums[right]] == 1) currentDiff++;
                right++;
            }
            if (currentDiff == diff) res += (n - right + 1);
            mp[nums[left]]--;
            if (mp[nums[left]] == 0) currentDiff--;
        }
        return res;
    }
};
