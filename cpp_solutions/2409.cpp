class Solution {
public:
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int getCummDays(string& dateStr) {
        int month = stoi(dateStr.substr(0, 2));
        int date = stoi(dateStr.substr(3, 2));
        int cumm = 0;
        for (int i = 0; i < month - 1; ++i) {
            cumm += days[i];
        }
        cumm += date;
        return cumm;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int arriveAliceDay = getCummDays(arriveAlice);
        int leaveAliceDay = getCummDays(leaveAlice);
        
        int arriveBobDay = getCummDays(arriveBob);
        int leaveBobDay = getCummDays(leaveBob);
        
        int arrive = max(arriveAliceDay, arriveBobDay);
        int leave = min(leaveAliceDay, leaveBobDay);
        return max(0, leave - arrive + 1);
    }
};