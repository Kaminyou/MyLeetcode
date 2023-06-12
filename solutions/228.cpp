class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> out;
        int n = nums.size();
        int index = 0;
        while (index < n) {
            int start = index;
            while (index + 1 < n && (long long)nums[index + 1] - (long long)nums[index] == 1) index++;
            if (index == start) {
                out.push_back(to_string(nums[index]));
            }
            else {
                out.push_back(to_string(nums[start]) + "->" + to_string(nums[index]));
            }
            index++;
        }
        return out;
    }
};