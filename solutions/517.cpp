class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for (auto& machine : machines) sum += machine;
        int n = machines.size();
        if (sum % n != 0) return -1;
        int target = sum / n;
        
        int toLeft = 0;
        int res = 0;
        for (auto& machine : machines) {
            int diff = machine - target;
            toLeft += diff;
            res = max({res, abs(toLeft), diff});
        }
        return res;
    }
};
