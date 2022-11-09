class StockSpanner {
public:
    stack<pair<int, int>> stk;
    int index;
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        while (!stk.empty() && stk.top().second <= price) stk.pop();
        int prev;
        if (stk.empty()) prev = -1;
        else prev = stk.top().first;
        
        stk.push({index, price});
        index++;
        return (index - 1) - prev;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */