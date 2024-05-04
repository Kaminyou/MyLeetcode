class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        int n = tickets.size();
        int target = tickets[k];
        for (int i = 0; i < n; ++i) {
            if (i > k) {
                res += min(tickets[i], target - 1);
            }
            else {
                res += min(tickets[i], target);
            }
        }
        return res;
    }
};
