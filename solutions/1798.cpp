class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int res = 0;
        sort(coins.begin(), coins.end());
        for (auto& coin : coins) {
            if (res + 1 >= coin) res += coin;
            else break;
        }
        return res + 1;
    }
};