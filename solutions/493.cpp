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
    
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> v = nums;
        int n = nums.size();
        BIT* bit = new BIT(n);
        sort(v.begin(), v.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[v[i]] = i + 1;
        }
        
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            int index = lower_bound(v.begin(), v.end(), nums[i] / 2.0) - v.begin();
            res += bit->getSum(index);
            bit->update(mp[nums[i]], 1);
        }
        return res;
    }
};
//    [1,3,2,3,1]
// => [1,1,2,3,3]
// => 1:2, 2:3, 3:5
//    [1,3,2,3,1]   BIT [0,0,1,0,0,0]
//             ^
//    [1,3,2,3,1]   BIT [0,0,1,0,0,1]
//           ^                 ^
//    

//    [1,2,4,4,2]
// => [1,2,2,4,4]
// => 1:1, 2:3, 4:5
//    [1,2,4,4,2]   BIT [0,0,0,1,0,0]
//             ^
//    [1,2,4,4,2]   BIT [0,0,0,1,0,1]
//           ^                 ^
//    