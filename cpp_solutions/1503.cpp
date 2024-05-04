class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (auto& num : left) {
            res = max(res, num);
        }
        for (auto& num : right) {
            res = max(res, n - num);
        }
        return res;
    }
};
