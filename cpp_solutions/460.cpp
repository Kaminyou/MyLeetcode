class LFUCache {
private:
    struct Node {
        int key;
        int value;
        int count;
    };
    int capacity;
    int lowest;
    unordered_map<int, list<Node>> count2list;
    unordered_map<int, list<Node>::iterator> key2node;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        lowest = 0;
    }
    
    int get(int key) {
        if (key2node.find(key) == key2node.end()) return -1;
        auto it = key2node[key];
        int res = it->value;
        update(key);
        return res;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (key2node.find(key) != key2node.end()) {
            update(key);
            key2node[key]->value = value;
            return;
        }
        if (key2node.size() == capacity) {
            auto it = count2list[lowest].rbegin();
            int deleteKey = it->key;
            key2node.erase(deleteKey);
            count2list[lowest].pop_back();
        }
        Node newNode = {key, value, 1};
        count2list[1].push_front(newNode);
        key2node[key] = count2list[1].begin();
        lowest = 1;
        return;
    }
    void update(int key) {
        auto it = key2node[key];
        int count = it->count;
        int value = it->value;
        key2node.erase(key);
        count2list[count].erase(it);
        if (count2list[count].size() == 0) {
            count2list.erase(count);
            if (count == lowest) lowest++;
        }
        Node newNode = {key, value, count + 1};
        count2list[count + 1].push_front(newNode);
        key2node[key] = count2list[count + 1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */