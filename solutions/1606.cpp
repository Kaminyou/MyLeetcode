typedef pair<int, int> P;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> servers;
        vector<int> serverWorks(k, 0);
        int maxWorks = 0;
        for (int i = 0; i < k; ++i) servers.insert(i); // serverID
        priority_queue<P, vector<P>, greater<P>> pq; // {end time, serverID}
        
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            int currArrival = arrival[i];
            int currLoad = load[i];
            while (!pq.empty() && pq.top().first <= currArrival) {
                auto [t, serverID] = pq.top();
                pq.pop();
                servers.insert(serverID);
            }
            
            if (servers.size() == 0) continue;
            int targetServer = i % k;
            // find forward
            auto it = servers.lower_bound(targetServer);
            
            // if not found, find from the first
            if (it == servers.end()) {
                it = servers.lower_bound(0);
            }
            
            int serverID = *it;
            serverWorks[serverID]++;
            maxWorks = max(maxWorks, serverWorks[serverID]);
            pq.push(make_pair(currArrival + currLoad, serverID));
            servers.erase(it);
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            if (serverWorks[i] == maxWorks) res.push_back(i);
        }
        return res;
    }
};