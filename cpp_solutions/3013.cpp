class SmartWindow {
private:
    int k;
    multiset<int> low, high;
    long long lowSum = 0;
public:
    SmartWindow(int k) {
        this->k = k;
    }
    int windowSize() {
        return low.size() + high.size();
    }
    void rebalance() {
        int need = min(k, windowSize());
        while (low.size() > need) {
            auto it = prev(low.end());
            int x = *it;
            lowSum -= x;
            low.erase(it);
            high.insert(x);
        }
        while (low.size() < need && !high.empty()) {
            auto it = high.begin();
            int x = *it;
            high.erase(it);
            low.insert(x);
            lowSum += x;
        }
    }
    void add(int x) {
        if (low.empty() || x <= *(low.rbegin())) {
            low.insert(x);
            lowSum += x;
        }
        else {
            high.insert(x);
        }
        rebalance();
    }
    void remove(int x) {
        auto it = low.find(x);
        if (it != low.end()) {
            low.erase(it);
            lowSum -= x;
        }
        else {
            it = high.find(x);
            if (it != high.end()) {
                high.erase(it);
            }
        }
        rebalance();
    }
    long long query() {
        return lowSum;
    }
};
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        SmartWindow *window = new SmartWindow(k - 1);
        int n = nums.size();
        for (int i = 1; i <= 1 + dist; ++i) {
            window->add(nums[i]);
        }
        long long res = window->query();
        for (int i = 2; i + dist < n; ++i) {
            window->remove(nums[i - 1]);
            window->add(nums[i + dist]);
            res = min(res, window->query());
        }
        return res + nums[0];
    }
};
