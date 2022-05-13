class Solution {
public:
    unordered_map<int, int> mp;
    int leastOpsExpressTarget(int x, int target) {
        if (mp.find(target) != mp.end()) return mp[target];
        if (x == target) return 0;
        if (x > target) {
            // x/x + x/x + ... + x/x or x - x/x - x/x ...
            int res = min(target * 2 - 1, (x - target) * 2);
            mp[target] = res;
            return mp[target];
        }
        long long sum = x;
        int count = 0;
        while (sum < target) {
            sum *= x;
            count++;
        }
        if (sum == target) return count;
        
        // sum > target
        int res1 = INT_MAX;
        int res2 = INT_MAX;
        // case1: by minus || target < sum < 2 * target
        // x^(count) - recursive result
        if (sum - target < target) {
            res1 = leastOpsExpressTarget(x, sum - target) + count;
        }
        // case2: by plus
        // x^(count - 1) + recursive result
        // minus 1: due to (count - 1)
        res2 = leastOpsExpressTarget(x, target - sum / x) + count - 1;
        
        // plus one is +/-
        mp[target] = min(res1, res2) + 1;
        return mp[target];
    }
};