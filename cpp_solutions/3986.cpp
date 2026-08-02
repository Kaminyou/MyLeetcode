class Solution {
public:
    int toSecond(string& time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return s + m * 60 + h * 60 * 60;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return toSecond(endTime) - toSecond(startTime);
    }
};
