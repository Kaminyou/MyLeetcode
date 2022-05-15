class BIT {
private:
    vector<int> tree;
public:
    BIT(int size) {
        tree = vector<int>(size + 1, 0);
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
    int getRange(int left, int right) {
        // inclusive
        return getSum(right) - getSum(left - 1);
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> mapping(n, 0);
        for (int i = 0; i < n; i++) {
            mapping[nums1[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            nums2[i] = mapping[nums2[i]];
        }
        
        BIT* bit1 = new BIT(n);
        vector<int> smallerBeforeSelf(n, 0);
        for (int i = 0; i < n; i++) {
            smallerBeforeSelf[i] = bit1->getRange(1, nums2[i] + 1);
            bit1->update(nums2[i] + 1, 1);
        }
        
        BIT* bit2 = new BIT(n);
        vector<int> largerAfterSelf(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            largerAfterSelf[i] = bit2->getRange(nums2[i] + 1, n);
            bit2->update(nums2[i] + 1, 1);
        }
        
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += static_cast<long long>(smallerBeforeSelf[i]) * largerAfterSelf[i];
        }
        return res;
    }
};