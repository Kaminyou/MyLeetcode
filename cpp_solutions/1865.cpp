class FindSumPairs {
public:
    unordered_map<int, int> counts;
    vector<int> nums;
    vector<int> nnums;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        nums.resize(nums1.size(), 0);
        nnums.resize(nums2.size(), 0);
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; ++i) nums[i] = nums1[i];
        for (int i = 0; i < m; ++i) nnums[i] = nums2[i];
        for (auto& num : nums2) counts[num]++;
    }
    
    void add(int index, int val) {
        int original = nnums[index];
        counts[original]--;
        counts[original + val]++;
        nnums[index] = original + val;
    }
    
    int count(int tot) {
        int res = 0;
        for (auto& num : nums) {
            int lack = tot - num;
            res += counts[lack];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

