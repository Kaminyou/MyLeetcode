class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long days = 0;
        unordered_map<int, long long> task2final;
        for (auto& task : tasks) {
            if (task2final.find(task) == task2final.end()) {
                days++;
            }
            else {
                days = max(days, task2final[task]) + 1;
            }
            task2final[task] = days + space;
        }
        return days;
    }
};