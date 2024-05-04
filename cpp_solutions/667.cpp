class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int left = 1;
        int right = n;
        vector<int> res;
        while (left <= right) {
            if (k > 1) {
                res.push_back(k-- % 2 ? left++ : right--);
            }
            else res.push_back(left++);
        }
        return res;
    }
};
