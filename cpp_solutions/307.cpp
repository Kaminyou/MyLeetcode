class BinaryIndexTree {
private:
    vector<int> BIT;
    int n;
public:
    // start from 1
    BinaryIndexTree(vector<int>& nums) {
        n = nums.size(); // [1 ... n]
        BIT = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            update(i + 1, nums[i]);
        }
    }
    void update(int index, int value) {
        while (index <= n) {
            BIT[index] += value;
            index += lsb(index);
        }
    }
    int query(int index) {
        int res = 0;
        while (index) {
            res += BIT[index];
            index -= lsb(index);
        }
        return res;
    }
    int lsb(int x) {
        return x & (-x);
    }
};
class NumArray {
public:
    BinaryIndexTree* bit;
    vector<int> numsCache;
    NumArray(vector<int>& nums) {
        bit = new BinaryIndexTree(nums);
        for (auto num : nums) numsCache.push_back(num);
    }
    
    void update(int index, int val) {
        bit->update(index + 1, val - numsCache[index]);
        numsCache[index] = val;
    }
    
    int sumRange(int left, int right) {
        return bit->query(right + 1) - bit->query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// V2
// class BIT {
// private:
//     vector<int> tree;
// public:
//     BIT(int size) {
//         tree.resize(size + 1, 0);
//     }
//     int lsb(int x) {
//         return x & (-x);
//     }
//     void add(int index, int value) {
//         while (index < tree.size()) {
//             tree[index] += value;
//             index += lsb(index);
//         }
//     }
//     int querySum(int index) {
//         int sum = 0;
//         while (index) {
//             sum += tree[index];
//             index -= lsb(index);
//         }
//         return sum;
//     }
//     int queryRange(int index1, int index2) {
//         return querySum(index2) - querySum(index1 - 1);
//     }
// };
// class NumArray {
// public:
//     vector<int>* nums;
//     BIT* bit;
//     NumArray(vector<int>& nums) {
//         this->nums = &nums;
//         int n = nums.size();
//         bit = new BIT(n);
//         for (int i = 0; i < nums.size(); ++i) {
//             bit->add(i + 1, nums[i]);
//         }
//     }
    
//     void update(int index, int val) {
//         int odd = (*nums)[index];
//         int diff = val - odd;
//         bit->add(index + 1, diff);
//         (*nums)[index] = val;
//     }
    
//     int sumRange(int left, int right) {
//         return bit->queryRange(left + 1, right + 1);
//     }
// };

// /**
//  * Your NumArray object will be instantiated and called as such:
//  * NumArray* obj = new NumArray(nums);
//  * obj->update(index,val);
//  * int param_2 = obj->sumRange(left,right);
//  */