class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int total = 0;
        int count = 0;
        while (total + count + 1 <= n) {
            count++;
            total += count;
        }
        return count;
    }
};