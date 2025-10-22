class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> mp;
        set<int> st;
        for (auto& num : nums) {
            mp[num]++;
            st.insert(num - k);
            st.insert(num);
            st.insert(num + k);
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = 0;
        int res = 0;
        for (int num : st) {
            while (left < n && nums[left] + k < num) left++;
            while (right < n && nums[right] - k <= num) right++;
            // [left, right)
            int cnt = right - left;
            int curr = mp[num];
            res = max(res, curr + min(cnt - curr, numOperations));
        }
        return res;
    }
};
