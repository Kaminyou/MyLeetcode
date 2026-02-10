class Manager {
private:
    unordered_map<int, int> mp;
    int odd;
    int even;
public:
    Manager() {
        odd = 0;
        even = 0;
    }
    void insert(int x) {
        if (!mp.count(x)) {
            if (x & 1) odd++;
            else even++;
        }
        mp[x]++;
    }
    void erase(int x) {
        mp[x]--;
        if (mp[x] == 0) {
            if (x & 1) odd--;
            else even--;
        }
    }
    bool isValid() {
        return odd == even && odd >= 1;
    }
};
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int left = 0; left < n; ++left) {
            Manager* manager = new Manager();
            for (int right = left; right < n; ++right) {
                manager->insert(nums[right]);
                if (manager->isValid()) res = max(res, right - left + 1);
            }
        }
        return res;
    }
};
