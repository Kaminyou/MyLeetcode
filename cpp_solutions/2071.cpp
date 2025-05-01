class Solution {
public:
    bool criteria(vector<int>& tasks, vector<int>& workers, int k, int pills, int strength) {
        // given pills and strength, can n workers complete k tasks?
        // tasks => small to large
        // workers => large to small
        multiset<int> st(workers.begin(), workers.begin() + k);
        for (int index = k - 1; index >= 0; index--) {
            int task = tasks[index];
            if (*st.rbegin() >= task) {
                int val = *st.rbegin();
                st.erase(st.find(val));
            } else {
                if (!pills) return false;
                pills--;
                int _task = task - strength;
                auto p = st.lower_bound(_task);
                if (p == st.end()) return false;
                st.erase(p);
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        int k = min(n, m);
        int left = 0;
        int right = k + 1;
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());
        while (left < right) {
            int mid = left + (right - left) / 2;
            bool response = criteria(tasks, workers, mid, pills, strength);
            
            if (!response) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};

