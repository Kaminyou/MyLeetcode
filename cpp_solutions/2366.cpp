class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        long long currMin = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= currMin) {
                currMin = nums[i];
                continue;
            }
            // greedly divide nums[i] -> [a,b,c...] s.t. max(a,b,c...) = currMin and maximum{a,b,c...}
            // i.e., if (nums[i] % currMin == 0) then divide -> [currMin, currMin ,currMin ...] || case 1
            //       else to [X, currMin, currMin, currMin ...] and maximum X || case 2
            // for case 1: do not update currMin
            // for case 2: update currMin to X
            
            long long divides = nums[i] / currMin;            
            if (nums[i] % currMin == 0) {
                res += divides - 1;
            }
            else {
                res += divides;
                currMin = nums[i] / (divides + 1);
            }
        }
        return res;
    }
};