class StockPrice {
public:
    unordered_map<int, int> timestamp2price; // time->price
    pair<int, int> latest; // time->price
    multiset<int> apex;
    
    StockPrice() {
        latest = make_pair(-1, -1);
    }
    
    void update(int timestamp, int price) {
        if (timestamp >= latest.first) {
            latest.first = timestamp;
            latest.second = price;
        }
        if (timestamp2price.find(timestamp) != timestamp2price.end()) {
            int oldPrice = timestamp2price[timestamp];
            apex.erase(apex.find(oldPrice));
        }
        timestamp2price[timestamp] = price;
        apex.insert(price);
    }
    
    int current() {
        return latest.second;
    }
    
    int maximum() {
        return *apex.rbegin();
    }
    
    int minimum() {
        return *apex.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */