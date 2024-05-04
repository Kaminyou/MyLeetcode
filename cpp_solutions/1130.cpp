class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> minStack;
        minStack.push_back(INT_MAX);
        
        int res = 0;
        for (auto num : arr) {
            while (!minStack.empty() && num >= minStack.back()) {
                int mid = minStack.back();
                minStack.pop_back();
                res += min(num, minStack.back()) * mid;
            }
            minStack.push_back(num);
        }
        
        for (int i = 2; i < minStack.size(); i++) {
            res += minStack[i - 1] * minStack[i];
        }
        return res;
    }
};
