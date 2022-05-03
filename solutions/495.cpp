class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int currEnd = -1;
        int sum = 0;
        for (auto time : timeSeries) {
            sum += duration;
            if (time < currEnd) sum -= (currEnd - time);
            currEnd = time + duration;
        }
        return sum;
    }
};