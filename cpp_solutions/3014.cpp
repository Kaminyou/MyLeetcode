class Solution {
public:
    int minimumPushes(string word) {
        int cost = 1;
        int res = 0;
        int n = word.size();
        while (n) {
            int curr = min(8, n);
            res += cost * curr;
            cost += 1;
            n -= curr;
        }
        return res;
    }
};

