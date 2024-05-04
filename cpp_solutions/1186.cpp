class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nonDelete = arr[0]; // store the value of normal Kadane's algo.
        int oneDelete = INT_MIN / 2; // store the value of one deletion
        int res = nonDelete;
        
        for (int i = 1; i < arr.size(); i++) {
            int num = arr[i];
            oneDelete = max(oneDelete + num, nonDelete); // skip the current one
            nonDelete = max(num, nonDelete + num);
            res = max({res, oneDelete, nonDelete});
        }
        return res;
    }
};