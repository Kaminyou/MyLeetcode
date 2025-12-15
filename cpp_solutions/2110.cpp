class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 0;
        int now = 1;
        int curr = -1;
        for (auto& price : prices) {
            if (price == curr - 1) now += 1;
            else now = 1;
            curr = price;
            res += now;
        }
        return res;
    }
};
