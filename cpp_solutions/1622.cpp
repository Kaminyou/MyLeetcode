class Fancy {
private:
    long long add;
    long long mul;
    long long mod = 1e9 + 7;
    vector<long long> nums;
    long long inv(long long a) {
        if (a == 1) return 1;
        return (mod - mod / a) * inv(mod % a) % mod;
    }
public:
    Fancy() {
        add = 0;
        mul = 1;
    }
    
    void append(int val) {
        nums.push_back(((val - add + mod) % mod) * inv(mul) % mod);
    }
    
    void addAll(int inc) {
        add += inc;
        add %= mod;
    }
    
    void multAll(int m) {
        add *= m;
        mul *= m;
        add %= mod;
        mul %= mod;
    }
    
    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        return (nums[idx] * mul + add) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
