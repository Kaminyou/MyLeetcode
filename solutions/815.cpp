class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> stop2bus;
        int n = routes.size();
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stop2bus[stop].push_back(i);
            }
        }
        
        unordered_set<int> visitedStop;
        vector<bool> visitedBus(501, false);
        visitedStop.insert(source);
        queue<pair<int, int>> q;
        for (auto bus : stop2bus[source]) {
            visitedBus[bus] = true;
            q.push(make_pair(bus, 1));
        }
        while (!q.empty()) {
            auto [bus, path] = q.front();
            q.pop();
            for (auto stop : routes[bus]) {
                if (stop == target) return path;
                if (visitedStop.find(stop) != visitedStop.end()) continue;
                for (auto nextBus : stop2bus[stop]) {
                    if (visitedBus[nextBus]) continue;
                    visitedBus[nextBus] = true;
                    visitedStop.insert(stop);
                    q.push(make_pair(nextBus, path + 1));
                }
            }
        }
        return -1;
    }
};