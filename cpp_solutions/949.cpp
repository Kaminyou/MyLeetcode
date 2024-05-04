class Solution {
public:
    string res = "";
    string vec2time(vector<int>& timeVec) {
        string time;
        time.push_back(timeVec[0] + '0');
        time.push_back(timeVec[1] + '0');
        time.push_back(':');
        time.push_back(timeVec[2] + '0');
        time.push_back(timeVec[3] + '0');
        return time;
    }
    void backtracking(vector<bool> used, vector<int>& arr, vector<int>& current) {
        if (current.size() == 4) {
            int hour = current[0] * 10 + current[1];
            int minute = current[2] * 10 + current[3];
            if (hour >= 24 || hour < 0) return;
            if (minute > 59 || minute < 0) return;
            if (res == "") res = vec2time(current);
            else {
                string time = vec2time(current);
                res = max(res, time);
            }
        }
        else {
            for (int i = 0; i < 4; ++i) {
                if (used[i]) continue;
                used[i] = true;
                current.push_back(arr[i]);
                backtracking(used, arr, current);
                current.pop_back();
                used[i] = false;
            }
        }
    }
    string largestTimeFromDigits(vector<int>& arr) {
        vector<bool> used(4, false);
        vector<int> current;
        backtracking(used, arr, current);
        return res;
    }
};
