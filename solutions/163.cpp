class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        nums.insert(nums.begin(), lower - 1);
        nums.push_back(upper + 1);
        
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= 1) continue;
            int left = nums[i - 1] + 1;
            int right = nums[i] - 1;
            if (left == right) res.push_back(to_string(left));
            else {
                string temp = to_string(left) + "->" + to_string(right);
                res.push_back(temp);
            }
        }
        return res;
    }
};