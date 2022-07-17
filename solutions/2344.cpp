class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int numsDivideSize = numsDivide.size();
        int gcdVal = numsDivide[0];
        
        for (int i = 1; i < numsDivideSize; ++i) {
            gcdVal = (int)__gcd(gcdVal, numsDivide[i]);
        }
        
        int count = 0;
        // find the smallest multi of gcdVal
        int smallest = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (gcdVal % nums[i] == 0) {
                smallest = min(smallest, nums[i]);
            }
        }
        if (smallest == INT_MAX) return -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < smallest) count++;
        }
        return count;
        
    }
};