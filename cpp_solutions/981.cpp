class TimeMap {
public:
    unordered_map<string, map<int, string>> key2values; // {key, {timestamp, value}}
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key2values[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (key2values.find(key) == key2values.end()) return "";
        auto it = key2values[key].upper_bound(timestamp);
        if (it == key2values[key].begin()) return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */