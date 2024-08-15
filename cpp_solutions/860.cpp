class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cnt(2, 0);
        for (auto& bill : bills) {
            if (bill == 5) cnt[0]++;
            else if (bill == 10) {
                cnt[0]--;
                cnt[1]++;
            }
            else if (bill == 20) {
                if (cnt[1] >= 1) {
                    cnt[0]--;
                    cnt[1]--;
                }
                else {
                    cnt[0] -= 3;
                }
            }
            if (cnt[0] < 0) return false;
            if (cnt[1] < 0) return false;
        }
        return true;
    }
};
