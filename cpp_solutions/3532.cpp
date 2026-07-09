class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> groups(n, -1);
        int index = 0;
        int groupID = 0;
        while (index < n) {
            int start = index;
            while (index + 1 < n && nums[index + 1] - nums[index] <= maxDiff) index++;
            // [start, index];
            for (int i = start; i <= index; ++i) {
                groups[i] = groupID;
            }
            groupID++;
            index++;
        }
        int m = queries.size();
        vector<bool> res;
        for (auto& q : queries) {
            if (groups[q[0]] == groups[q[1]]) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
