class LRUCache {
public:
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> cache;
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        auto it = mp[key];
        cache.splice(cache.begin(), cache, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }
        if (mp.size() == capacity_) {
            auto [k, v] = cache.back();
            cache.pop_back();
            mp.erase(k);
        }
        cache.push_front(make_pair(key, value));
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// V2
// class LRUCache {
// public:
//     int _capacity;
//     unordered_map<int, pair<int, int>> mp; // key => {value, count}
//     queue<int> q; // key
//     LRUCache(int capacity) {
//         _capacity = capacity;
//     }
    
//     int get(int key) {
//         if (mp.find(key) == mp.end()) return -1;
//         mp[key].second++;
//         q.push(key);
//         return mp[key].first;
//     }
    
//     void put(int key, int value) {
//         if (mp.find(key) != mp.end()) {
//             mp[key].first = value;
//             mp[key].second++;
//             q.push(key);
//         }
//         else {
//             while (mp.size() >= _capacity) {
//                 int k = q.front();
//                 q.pop();
//                 mp[k].second--;
//                 if (mp[k].second == 0) mp.erase(k);
//             }
//             mp[key] = make_pair(value, 1);
//             q.push(key);
//         }
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */