class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        if (v1[1] == v2[1]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        int sum = 0;
        unordered_set<int> st;
        sort(tasks.begin(), tasks.end(), compare);
        for (auto& task : tasks) {
            int start = task[0];
            int end = task[1];
            int duration = task[2];
            int already = 0;
            for (int i = start; i <= end; ++i) {
                if (st.count(i)) already++;
            }
            if (already >= duration) continue;
            int lack = duration - already;
            while (lack) {
                if (!st.count(end)) {
                    st.insert(end);
                    sum++;
                    lack--;
                }
                end--;
            }
        }
        return sum;
    }
};