class Bank {
private:
    vector<long long> _balance;
    int n;
public:
    Bank(vector<long long>& balance) {
        int n = balance.size();
        this->n = n;
        _balance.resize(n, 0);
        for (int i = 0; i < n; ++i) _balance[i] = balance[i];
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n) return false;
        if (account2 > n) return false;
        if (_balance[account1 - 1] < money) return false;
        _balance[account1 - 1] -= money;
        _balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > n) return false;
        _balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > n) return false;
        if (_balance[account - 1] < money) return false;
        _balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
