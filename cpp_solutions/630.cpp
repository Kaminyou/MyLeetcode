class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare);
        int totalTime = 0;
        priority_queue<int> pq;
        for (auto& course : courses) {
            totalTime += course[0];
            pq.push(course[0]);
            if (totalTime > course[1]) {
                totalTime -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};