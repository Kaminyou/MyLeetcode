class SegmentTree {
private:
    vector<int> segtree;
    int n;
public:
    SegmentTree(int size, int n) {
        segtree.resize(size, 0);
        this->n = n;
    }
    void update(int idx, int x) {
        idx += n;
        while (idx) {
            segtree[i] = max(segtree[i], x);
            idx /= 2;
        }
    }
    int query(int lo, int hi) {
        int ans = INT_MIN;
        lo += n;
        hi += n + 1;
        while (lo < hi) {
            if (lo % 2 == 1) {
                ans = max(ans, segtree[lo]);
                lo += 1;
            }
            if (hi % 2 == 1) {
                hi -= 1;
                ans = max(ans, segtree[hi]);
            }
            lo /= 2;
            hi /= 2;
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        vector<int> sortNums = nums;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int n = sortNums.size();
        for (int i = 0; i < n; ++i) {
            mp[sortNums[i]] = i;
        }
        int res = 0;
        SegmentTree* segmentTree = new SegmentTree(300000, (int)nums.size());
        for (auto& num : nums) {
            int lo = lower_bound(sortNums.begin(), sortNums.end(), num - k);
            int hi = upper_bound(sortNums.begin(), sortNums.end(), num - 1);
            int cnt = segmentTree->query(lo, hi);
            update(mp[num], count + 1);
            res = max(res, count + 1);
        }
        return res;
    }
};