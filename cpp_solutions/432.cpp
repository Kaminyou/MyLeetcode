class AllOne {
private:
    struct Node {
        int value;
        unordered_set<string> keys;
    };
    list<Node> l;
    unordered_map<string, list<Node>::iterator> mp;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        auto it = mp.find(key);
        
        // not exist
        if (it == mp.end()) {
            // original list does not have "1"
            if (l.empty() || l.front().value != 1) {
                l.push_front({1, {key}});
            }
            // original list has "1"
            else {
                l.front().keys.insert(key);
            }
            // mp
            mp[key] = l.begin();
            return;
        }
        
        // exist
        auto nodeIt = it->second;
        auto nextNodeIt = next(nodeIt);
        // original list does not have next
        if (nextNodeIt == l.end() || nextNodeIt->value != nodeIt->value + 1) {
            nextNodeIt = l.insert(nextNodeIt, {nodeIt->value + 1, {}});
        }
        nextNodeIt->keys.insert(key);
        
        // mp
        mp[key] = nextNodeIt;
        
        // clear list
        nodeIt->keys.erase(key);
        if (nodeIt->keys.empty()) l.erase(nodeIt);
    }
    
    void dec(string key) {
        auto it = mp.find(key);
        if (it == mp.end()) return;
        
        auto nodeIt = it->second;
        if (nodeIt->value > 1) {
            auto prevNodeIt = prev(nodeIt);
            if (nodeIt == l.begin() || prevNodeIt->value != nodeIt->value - 1) {
                prevNodeIt = l.insert(nodeIt, {nodeIt->value - 1, {}});
            }
            prevNodeIt->keys.insert(key);
            mp[key] = prevNodeIt;
        }
        else {
            mp.erase(key);
        }
        
        // clear list
        nodeIt->keys.erase(key);
        if (nodeIt->keys.empty()) l.erase(nodeIt);
    }
    
    string getMaxKey() {
        if (l.empty()) return "";
        return *(l.back().keys.begin());
    }
    
    string getMinKey() {
        if (l.empty()) return "";
        return *(l.front().keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */