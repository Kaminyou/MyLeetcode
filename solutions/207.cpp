class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto& prerequisite : prerequisites) {
            inDegrees[prerequisite[1]]++;
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }
        queue<int> courses;
        int count = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0) {
                count++;
                courses.push(i);
            }
        }
        while (!courses.empty()) {
            int course = courses.front();
            courses.pop();
            for (auto& neighbor : graph[course]) {
                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) {
                    courses.push(neighbor);
                    count++;
                }
            }
        }
        return count == numCourses;
    }
};