class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int lo = INT_MAX;
        int hi = INT_MIN;
        for (auto& num : nums) {
            lo = min(lo, num);
            hi = max(hi, num);
        }
        
        int n = nums.size();
        if (n == 1) return 0;
        int gap = max((hi - lo) / (n - 1), 1);
        int size = (hi - lo) / gap + 1;
        
        vector<int> bucketsLo(size, INT_MAX);
        vector<int> bucketsHi(size, INT_MIN);
        for (auto& num : nums) {
            int index = (num - lo) / gap;
            bucketsLo[index] = min(bucketsLo[index], num);
            bucketsHi[index] = max(bucketsHi[index], num);
        }
        
        int res = 0;
        int currHi = bucketsHi[0];
        for (int i = 1; i < size; ++i) {
            if (bucketsLo[i] == INT_MAX || bucketsHi[i] == INT_MIN) continue;
            res = max(res, bucketsLo[i] - currHi);
            currHi = bucketsHi[i];
        }
        return res;
    }
};