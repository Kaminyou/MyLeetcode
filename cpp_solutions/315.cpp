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
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int base = 10001;
        BIT* bit = new BIT(base * 2 + 1);
        
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            
            int x = nums[i];
            res[i] = bit->getSum(x + base - 1);
            bit->update(x + base, 1);
        }
        return res;
    }
};