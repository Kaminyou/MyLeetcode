class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int n, int curr, int sum, int target, vector<int>& path, vector<int>& candidates) {
        if (target == sum) {
            res.push_back(path);
            return;
        }
        for (int i = curr; i < n; ++i) {
            if (sum + candidates[i] > target) break;
            path.push_back(candidates[i]);
            backtracking(n, i + 1, sum + candidates[i], target, path, candidates);
            // skip duplicates
            while (i + 1 < n && candidates[i] == candidates[i + 1]) i++;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        backtracking(n, 0, 0, target, path, candidates);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& current, int index, vector<int>& nums, unordered_map<int, int>& mp, int target) {
        int n = nums.size();
        if (target == 0) {
            res.push_back(current);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = index; i < n; ++i) {
            int num = nums[i];
            int cnt = mp[num];
            for (int j = 1; j <= cnt; ++j) {
                current.push_back(num);
                backtracking(current, i + 1, nums, mp, target - j * num);
            }
            for (int j = 1; j <= cnt; ++j) {
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> mp;
        for (auto& candidate : candidates) {
            mp[candidate]++;
        }
        vector<int> nums;
        for (auto& [num, cnt] : mp) {
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end());
        vector<int> current;
        backtracking(current, 0, nums, mp, target);
        return res;
    }
};
