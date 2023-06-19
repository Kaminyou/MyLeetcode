class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int current = 0;
        for (auto num : gain) {
            current += num;
            highest = max(highest, current);
        }
        return highest;
    }
};