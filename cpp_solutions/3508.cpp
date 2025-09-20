class Router {
private:
    int memoryLimit;
    unordered_set<long long> hash;
    unordered_map<int, deque<int>> des2times;
    //unordered_map<int, multiset<int>> des2times;
    queue<long long> q;
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    long long toNum(int source, int destination, int timestamp) {
        return ((long long)source << 40) + ((long long)destination << 20) + ((long long)timestamp);
    }
    vector<int> backToPacket(long long num) {
        int source = (int)(num >> 40);
        int destination = (int)((num & ((1LL << 40) - 1)) >> 20);
        int timestamp = (int)(num & ((1LL << 20) - 1));
        return {source, destination, timestamp};
    }
    bool addPacket(int source, int destination, int timestamp) {
        long long num = toNum(source, destination, timestamp);
        if (hash.count(num)) return false;
        hash.insert(num);
        q.push(num);
        des2times[destination].push_back(timestamp);
        if (q.size() > memoryLimit) {
            long long n = q.front();
            q.pop();
            vector<int> packet = backToPacket(n);
            int ss = packet[0];
            int dd = packet[1];
            int tt = packet[2];
            hash.erase(n);
            des2times[dd].pop_front();
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        long long n = q.front();
        q.pop();
        vector<int> packet = backToPacket(n);
        int ss = packet[0];
        int dd = packet[1];
        int tt = packet[2];
        hash.erase(n);
        des2times[dd].pop_front();
        return {ss, dd, tt};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        const auto& s = des2times[destination];
        auto l = lower_bound(s.begin(), s.end(), startTime);
        auto r = upper_bound(s.begin(), s.end(), endTime);
        return static_cast<int>(std::distance(l, r));
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
