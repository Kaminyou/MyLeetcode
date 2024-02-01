class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            int current = nums[i];
            int last = nums[min(n - 1, i + 2)];
            if (last - current > k) return {};
            vector<int> temp;
            for (int j = i; j < min(i + 3, n); ++j) {
                temp.push_back(nums[j]);
            }
            out.push_back(temp);
        }
        return out;
    }
};
