class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int now = 0;
        int res = 0;
        for (auto& t : target) {
            if (t > now) {
                res += (t - now);
            }
            now = t;
        }
        return res;
    }
};
