class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        
        int index = 0;
        while (index < n) {
            int left = intervals[index][0];
            int right = intervals[index][1];
            while (index + 1 < n && intervals[index + 1][0] <= right) {
                right = max(right, intervals[index + 1][1]);
                index++;
            }
            ans.push_back({left, right});
            index++;
        }
        return ans;
    }
};