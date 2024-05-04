/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> mp;
        for (auto oneSchedule : schedule) {
            for (auto interval : oneSchedule) {
                mp[interval.start]++;
                mp[interval.end]--;
            }
        }
        
        vector<Interval> res;
        int count = 0;
        for (auto element : mp) {
            count += element.second;
            if (count == 0) {
                Interval interval(element.first, 0);
                res.push_back(interval);
            }
            if (count != 0 && res.size() > 0 && res.back().end == 0) res.back().end = element.first;
        }
        // remove the last one
        if (res.size() > 0) res.pop_back();
        return res;
    }
};