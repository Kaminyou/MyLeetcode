class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        if (n == 1) return 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto stick : sticks) q.push(stick);
        
        int sum = 0;
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a + b);
            sum += a + b;
        }
        return sum;
    }
};