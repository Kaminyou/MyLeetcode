class Solution {
public:
    int time2int(string& time) {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        return hour * 60 + minute;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<int> event1Time(2, 0);
        vector<int> event2Time(2, 0);
        event1Time[0] = time2int(event1[0]);
        event1Time[1] = time2int(event1[1]);
        event2Time[0] = time2int(event2[0]);
        event2Time[1] = time2int(event2[1]);
        int start = max(event1Time[0], event2Time[0]);
        int end = min(event1Time[1], event2Time[1]);
        return start <= end;
    }
};