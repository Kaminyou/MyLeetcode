typedef pair<int, char> P;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> task2cnt;
        for (auto c : tasks) task2cnt[c]++;
        priority_queue<P> pq;
        
        for (auto& element : task2cnt) {
            pq.push({element.second, element.first});
        }
        
        int totalTime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<P> v;
            for (int i = 0; i < cycle; ++i) {
                if (!pq.empty()) {
                    v.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (auto p : v) {
                if (--p.first) {
                    pq.push(p);
                }
            }
            totalTime += !pq.empty() ? cycle : time;
        }
        return totalTime;
    }
};
