class SegmentTree {
public:
    int n;
    vector<int> sum, mn, mx;

    SegmentTree(int n_) : n(n_), sum(4 * n_, 0), mn(4 * n_, 0), mx(4 * n_, 0) {}

    void pull(int node) {
        /* Helper to recompute information of node by it's children */

        int lc = node * 2, rc = node * 2 + 1;

        sum[node] = sum[lc] + sum[rc];
        mn[node] = std::min(mn[lc], sum[lc] + mn[rc]);
        mx[node] = std::max(mx[lc], sum[lc] + mx[rc]);
    }

    void update(int idx, int val) { 
        update(1, 0, n - 1, idx, val); 
    }

    void update(int node, int l, int r, int idx, int val) {
        /* Update value by index idx in original array */

        if (l == r) {
            sum[node] = val;
            mn[node] = val;
            mx[node] = val;
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m) 
            update(node * 2, l, m, idx, val);
        else 
            update(node * 2 + 1, m + 1, r, idx, val);

        pull(node);
    }

    bool exist(int node, int sum_before, int target) const {
        int need = target - sum_before;
        return mn[node] <= need && need <= mx[node];
    }

    int find_rightmost_prefix(int target = 0) {
        return find_rightmost_prefix(1, 0, n - 1, 0, target);
    }

    int find_rightmost_prefix(int node, int l, int r, int sum_before, int target) {
        /* Find rightmost index r with prefixsum(r) = target */

        if (!exist(node, sum_before, target)) 
            return -1;
        if (l == r) 
            return l;

        int m = (l + r) / 2;
        int lc = node * 2, rc = node * 2 + 1;

        // Check right half first
        int sum_before_right = sum_before + sum[lc];
        if (exist(rc, sum_before_right, target))
            return find_rightmost_prefix(rc, m + 1, r, sum_before_right, target);

        return find_rightmost_prefix(lc, l, m, sum_before, target);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        SegmentTree stree(n);  // SegmentTree over balance array for current l
        unordered_map<int, int> first;  // val -> first occurence idx for current l

        int result = 0;
        for (int l = n - 1; l >= 0; --l) {
            int x = nums[l];

            // If x already had a first occurrence to the right, remove that old marker.
            auto it = first.find(x);
            if (it != first.end())
                stree.update(it->second, 0);

            // Now x becomes first occurrence at l.
            first[x] = l;
            stree.update(l, ((x & 1) == 0) ? 1 : -1); // set new marker

            // Find rightmost r >= l such that sum(w[l..r]) == 0
            int r = stree.find_rightmost_prefix(0);
            if (r >= l) 
                result = std::max(result, r - l + 1);
        }

        return result;
    }
};
