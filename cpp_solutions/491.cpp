class Solution {
public:
    string encode(vector<int>& nums) {
        string s;
        for (auto& num : nums) {
            s += to_string(num);
            s += "_";
        }
        return s;
    }
    unordered_set<string> st;
    vector<vector<int>> res;
    void backtracking(int index, vector<int>& nums, vector<int>& selection) {
        if (index == nums.size()) {
            if (selection.size() < 2) return;
            string s = encode(selection);
            if (!st.count(s)) {
                res.push_back(selection);
                st.insert(s);
            }
            return;
        }
        int n = selection.size();
        if (n == 0 || selection[n - 1] <= nums[index]) {
            selection.push_back(nums[index]);
            backtracking(index + 1, nums, selection);
            selection.pop_back();

        }
        backtracking(index + 1, nums, selection);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> selection;
        backtracking(0, nums, selection);
        return res;
    }
};