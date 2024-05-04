class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int index = 0;
        vector<vector<int>> res;
        
        while (index < n && intervals[index][1] < newInterval[0]) {
            res.push_back(intervals[index]);
            index++;
        }
        
        while (index < n && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        res.push_back(newInterval);
        
        while (index < n) {
            res.push_back(intervals[index]);
            index++;
        }
        return res;
    }
};