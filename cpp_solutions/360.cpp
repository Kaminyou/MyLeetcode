class Solution {
public:
    int function(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (a == 0) {
            if (b < 0) {
                reverse(nums.begin(), nums.end());
            }
            for (int i = 0; i < nums.size(); ++i) {
                nums[i] = function(nums[i], a, b, c);
            }
            return nums;
        }
        
        double middle = static_cast<double>(-b) / (2 * a);
        int n = nums.size();
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        while (left <= right) {
            if (abs(middle - (double)nums[left]) > abs((double)nums[right] - middle)) {
                res.push_back(nums[left]);
                left++;
            }
            else {
                res.push_back(nums[right]);
                right--;
            }
        }
        
        for (int i = 0; i < res.size(); ++i) {
            res[i] = function(res[i], a, b, c);
        }
        if (a > 0) reverse(res.begin(), res.end());
        return res;
    }
};