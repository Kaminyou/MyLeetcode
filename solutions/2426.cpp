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
    void update(int index, int value) {
        while (index < tree.size()) {
            tree[index] += value;
            index += lsb(index);
        }
    }
    int getSum(int index) {
        int sum = 0;
        while (index) {
            sum += tree[index];
            index -= lsb(index);
        }
        return sum;
    }
    int queryRange(int low, int high) {
        // [low, high]
        return getSum(high) - getSum(low - 1);
    }
};
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        BIT* bit = new BIT(60006);
        int base = 30003;
        int n = nums1.size();
        vector<int> nums1MinusNums2(n, 0);
        for (int i = 0; i < n; ++i) nums1MinusNums2[i] = nums1[i] - nums2[i];
        
        long long res = 0;
        for (int i = n - 1; i >= 0; --i) {
            int cnt = bit->queryRange(nums1MinusNums2[i] + base, 60006);
            res += cnt;
            bit->update(nums1MinusNums2[i] + base + diff, 1);
        }
        return res;
    }
};
// i < j
// nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
// nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff => query [nums1[j] - nums2[j] + diff, ...]