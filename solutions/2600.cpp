class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int res = 0;

        res += min(numOnes, k);
        k -= min(numOnes, k);
        
        k -= min(numZeros, k);
        
        res += -1 * min(numNegOnes, k);
        k -= min(numNegOnes, k);

        return res;
    }
};