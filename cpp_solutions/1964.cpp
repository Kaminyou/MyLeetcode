class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis;
        int n = obstacles.size();
        for (int i = 0; i < n; ++i) {
            int obstacle = obstacles[i];
            if (lis.empty() || obstacle >= lis.back()) {
                lis.push_back(obstacle);
                obstacles[i] = lis.size();
            }
            else {
                int index = upper_bound(lis.begin(), lis.end(), obstacle) - lis.begin();
                lis[index] = obstacle;
                obstacles[i] = index + 1;
            }
        }
        return obstacles;
    }
};