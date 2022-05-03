class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int posProduct = nums[0];
        int negProduct = nums[0];
        int maxVal = nums[0];
        
        for (int i = 1; i < n; i++) {
            int nextPos, nextNeg;

            nextPos = max({nums[i], posProduct * nums[i], negProduct * nums[i]});
            nextNeg = min({nums[i], posProduct * nums[i], negProduct * nums[i]});
            maxVal = max(maxVal, nextPos);
            
            posProduct = nextPos;
            negProduct = nextNeg;
        }
        return maxVal;
    }
};