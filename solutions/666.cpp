class Solution {
public:
    unordered_map<int, unordered_map<int, int>> tree;
    int sum = 0;
    int dfs(int currLevel, int currPosition) {
        // return # of leave
        if (tree.find(currLevel) == tree.end()) return 0;
        if (tree[currLevel].find(currPosition) == tree[currLevel].end()) return 0;
        if (tree.find(currLevel + 1) == tree.end()) {
            sum += tree[currLevel][currPosition];
            return 1;
        }
        if (tree[currLevel + 1].find(currPosition * 2) == tree[currLevel + 1].end() && tree[currLevel + 1].find(currPosition * 2 + 1) == tree[currLevel + 1].end()) {
            sum += tree[currLevel][currPosition];
            return 1;
        }
        int left = dfs(currLevel + 1, currPosition * 2);
        int right = dfs(currLevel + 1, currPosition * 2 + 1);
        sum += tree[currLevel][currPosition] * (left + right);
        return left + right;
    }
    int pathSum(vector<int>& nums) {
        for (auto& num : nums) {
            int level = num / 100;
            num %= 100;
            int position = num / 10;
            num %= 10;
            int value = num;
            tree[level][position - 1] = value;
        } 
        dfs(1, 0);
        return sum;
    }
};