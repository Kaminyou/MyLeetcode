class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> hashPrefix(51, 0);
        vector<int> hashSuffix(51, 0);
        int distinctPrefix = 0;
        int distinctSuffix = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            hashSuffix[nums[i]]++;
            if (hashSuffix[nums[i]] == 1) distinctSuffix++;
        }
        
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            hashPrefix[nums[i]]++;
            if (hashPrefix[nums[i]] == 1) distinctPrefix++;
            hashSuffix[nums[i]]--;
            if (hashSuffix[nums[i]] == 0) distinctSuffix--;
            res[i] = distinctPrefix - distinctSuffix;
        }
        return res;
    }
};