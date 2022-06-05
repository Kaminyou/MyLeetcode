class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> value2idx;
        for (int i = 0; i < nums.size(); ++i) {
            value2idx[nums[i]] = i;
        }
        for (auto& operation : operations) {
            int from = operation[0];
            int to = operation[1];
            int index = value2idx[from];
            value2idx.erase(from);
            value2idx[to] = index;
        }
        for (auto& element : value2idx) {
            int value = element.first;
            int index = element.second;
            nums[index] = value;
        }
        return nums;
    }
};