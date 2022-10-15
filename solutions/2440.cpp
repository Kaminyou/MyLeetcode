class Solution {
public:
    vector<vector<int>> adjacency;
    vector<int> nums;
    int dfs(int current, int parent, int& components, int targetVal) {
        int sum = nums[current];
        for (auto& neighbor : adjacency[current]) {
            if (neighbor == parent) continue;
            sum += dfs(neighbor, current, components, targetVal);
        }
        
        if (sum == targetVal) {
            components--;
            return 0;
        }
        return sum;
    }
    int isDivisible(int components, int targetVal) {
        int tempComponents = components;
        dfs(0, -1, components, targetVal);
        if (components == 0) return tempComponents - 1;
        return -1;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        int n = nums.size();
        adjacency.resize(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        
        if (count(nums.begin(), nums.end(), nums[0]) == n) return n - 1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int res = 0;
        for (int i = 2; i * i <= sum; ++i) {
            if (sum % i == 0) {
                int components = i;
                int targetVal = sum / i;
                res = max(res, isDivisible(components, targetVal));
                res = max(res, isDivisible(targetVal, components));
            }
        }
        return res;
    }
};