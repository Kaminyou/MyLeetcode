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
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        BIT* bitLeft = new BIT(n + 1);
        BIT* bitRight = new BIT(n + 1);
        for (int i = 0; i < n; ++i) bitRight->update(nums[i], 1);
        
        long long res = 0;
        for (int k = 0; k < n; ++k) {
            bitRight->update(nums[k], - 1);
            for (int j = 0; j < k; ++j) {
                bitLeft->update(nums[j], 1);
                if (nums[k] < nums[j]) {
                    res += (long long)bitRight->getRange(nums[j] + 1, n) * (long long)bitLeft->getRange(1, nums[k] - 1);
                }
            }
            for (int j = 0; j < k; ++j) bitLeft->update(nums[j], - 1);
        }

        return res;
    }
};