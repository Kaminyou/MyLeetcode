class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int meetingCnt = 0;
        sort(meetings.begin(), meetings.end());
        int start = INT_MAX;
        int end = -1;
        for (auto& meeting : meetings) {
            if (meeting[0] > end) {
                if (end != -1) meetingCnt += end - start + 1;
                start = meeting[0];
                end = meeting[1];
            }
            else {
                start = min(start, meeting[0]);
                end = max(end, meeting[1]);
            }
        }
        meetingCnt += end - start + 1;
        return days - meetingCnt;
    }
};
