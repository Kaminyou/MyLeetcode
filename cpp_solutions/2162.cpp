class Solution {
public:
    int cost(int mins, int secs, int startAt, int moveCost, int pushCost) {
        if (mins > 99 || mins < 0 || secs > 99 || secs < 0) return INT_MAX;
        string target = to_string(mins * 100 + secs);
        char curr = startAt + '0';
        int res = 0;
        for (auto& c : target) {
            if (c == curr) res += pushCost;
            else {
                res += (pushCost + moveCost);
                curr = c;
            }
        }
        return res;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int mins = targetSeconds / 60;
        int secs = targetSeconds % 60;
        return min(cost(mins, secs, startAt, moveCost, pushCost), 
                   cost(mins - 1, secs + 60, startAt, moveCost, pushCost));
    }
};