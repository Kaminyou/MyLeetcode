class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        int left = toBeRemoved[0];
        int right = toBeRemoved[1];
        int t;
        for (auto interval : intervals) {
            // min of current interval's right with remove's left
            t = min(interval[1], left);
            if (t > interval[0]) ans.push_back({interval[0], t});
            // max of current interval's left with remove's right
            t = max(interval[0], right);
            if (t < interval[1]) ans.push_back({t, interval[1]});
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        for (auto& interval : intervals) {
            int left = max(interval[0], toBeRemoved[0]);
            int right = min(interval[1], toBeRemoved[1]);
            // case 0: no touch
            if (left >= right) res.push_back(interval);
            // case 1: toBeRemoved cover interval
            else if (interval[0] >= toBeRemoved[0] && interval[1] <= toBeRemoved[1]) continue;
            // case 2: interval cover toBeRemoved
            else if (interval[0] < toBeRemoved[0] && interval[1] > toBeRemoved[1]) {
                res.push_back({interval[0], toBeRemoved[0]});
                res.push_back({toBeRemoved[1], interval[1]});
            }
            // case 3: right touch
            else if (interval[0] < toBeRemoved[0]) {
                res.push_back({interval[0], toBeRemoved[0]});
            }
            // case 4: left touch
            else {
                res.push_back({toBeRemoved[1], interval[1]});
            }
        }
        return res;
    }
};