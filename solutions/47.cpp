class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, vector<bool>& visited, vector<int>& path) {
        int n = nums.size();
        if (path.size() == n) {
            res.push_back(path);
            return;
        }
        int index = 0;
        while (index < n) {
            if (!visited[index]) {
                int curr = nums[index];
                path.push_back(curr);
                visited[index] = true;
                backtracking(nums, visited, path);
                visited[index] = false;
                path.pop_back();

                while (index + 1 < n && nums[index + 1] == curr) index++;
            }
            index++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> visited(n, false);
        vector<int> path;
        backtracking(nums, visited, path);
        return res;
    }
};