class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int index = 0;
        int res = 0;
        int n = colors.size();
        while (index < n) {
            int start = index;
            char c = colors[index];
            int sumTime = neededTime[index];
            int maxTime = neededTime[index];
            while (index + 1 < n && colors[index + 1] == c) {
                index++;
                sumTime += neededTime[index];
                maxTime = max(maxTime, neededTime[index]);
            }
            if (index - start + 1 >= 2) {
                res += sumTime - maxTime;
            }
            index++;
        }
        return res;
    }
};