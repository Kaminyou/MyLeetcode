class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int m = (1 << n);
        for (int i = 0; i < m; ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};