class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if (n & 1) res.push_back(0);
        int curr = 1;
        for (int i = (n & 1); i < n; i += 2) {
            res.push_back(curr);
            res.push_back(-curr);
            curr++;
        }
        return res;
    }
};