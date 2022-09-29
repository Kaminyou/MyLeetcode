class BIT {
private:
    vector<int> tree;
public:
    BIT(int size) {
        tree.resize(size + 1, 0);
    }
    int lsb(int x) {
        return x & (-x);
    }
    void add(int idx, int value) {
        while (idx < tree.size()) {
            tree[idx] += value;
            idx += lsb(idx);
        }
    }
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= lsb(idx);
        }
        return sum;
    }
};
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        vector<int> diff;
        int n = nums1.size();
        
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (int i = 0; i < n; ++i) {
            diff.push_back(nums1[i] - nums2[i]);
            minVal = min({minVal, diff[i], -diff[i]});
            maxVal = max({maxVal, diff[i], -diff[i]});
        }
        BIT* bit = new BIT(maxVal - minVal + 1);
        long long res = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            res += bit->query(diff[i] - minVal);
            bit->add(-diff[i] - minVal + 1, 1);
        }
        return res;
    }
};

