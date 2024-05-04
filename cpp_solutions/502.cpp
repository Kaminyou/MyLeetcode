class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int, int>> projects;
        int n = profits.size();
        for (int i = 0; i < n; ++i) projects.push_back(make_pair(capital[i], profits[i]));
        sort(projects.begin(), projects.end());
        
        int projectIdx = 0;
        while (projectIdx < n && projects[projectIdx].first <= w) {
            pq.push(projects[projectIdx].second);
            projectIdx++;
        }
        
        while (!pq.empty() && k) {
            int currMax = pq.top();
            pq.pop();
            w += currMax;
            while (projectIdx < n && projects[projectIdx].first <= w) {
                pq.push(projects[projectIdx].second);
                projectIdx++;
            }
            
            k--;
        }
        return w;
    }
};