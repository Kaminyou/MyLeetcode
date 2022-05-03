class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
        prefix = {1};
    }
    
    void add(int num) {
        if (num == 0) prefix = {1};
        else{
            int curr = prefix.back();
            prefix.push_back(num * curr);
        }
    }
    
    int getProduct(int k) {
        if (k > prefix.size() - 1) return 0;
        return prefix.back() / prefix[prefix.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */