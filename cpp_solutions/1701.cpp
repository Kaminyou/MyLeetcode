class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double now = 0.0;
        double wait = 0.0;
        for (auto& customer : customers) {
            now = max(double(customer[0] + customer[1]), now + customer[1]);
            wait += now - customer[0];
        }
        int n = customers.size();
        return wait / n;
    }
};
