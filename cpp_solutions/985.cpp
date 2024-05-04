class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for (auto& num : nums) {
            if (num & 1) continue;
            sum += num;
        }
        vector<int> res;
        for (auto& query : queries) {
            int index = query[1];
            int value = query[0];
            if (!(nums[index] & 1)) sum -= nums[index];
            nums[index] += value;
            if (!(nums[index] & 1)) sum += nums[index];
            res.push_back(sum);
        }
        return res;
    }
};