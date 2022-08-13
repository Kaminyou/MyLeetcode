class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> st;
        for (int i = 0; i < k; ++i) st.insert(nums[i]);
        auto mid = next(st.begin(), (k - 1) / 2);
        
        for (int i = k; i <= nums.size(); ++i) {
            double ans = ((double)(*mid) + *next(mid, (k + 1) % 2)) / 2.0;
            res.push_back(ans);
            if (i == nums.size()) break;
            st.insert(nums[i]);
            if (nums[i] < *mid) mid--;
            if (nums[i - k] <= *mid) mid++;
            st.erase(st.lower_bound(nums[i - k]));
        }
        return res;
    }
};