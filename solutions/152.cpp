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

// v2
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int positive = 0;
//         int negative = 0;
//         int res = INT_MIN;
//         for (auto& num : nums) {
//             if (num == 0) {
//                 positive = 0;
//                 negative = 0;
//                 res = max(res, 0);
//             }
//             else if (num > 0) {
//                 positive = max(num, positive * num);
//                 negative = min(num, negative * num);
//                 res = max(res, positive);
//             }
//             else {
//                 int temp = positive;
//                 positive = max(0, negative * num);
//                 if (positive > 0) res = max(res, positive);
//                 negative = min(num, temp * num);
//                 res = max(res, negative);
//             }
            
//         }
//         return res;
//     }
// };