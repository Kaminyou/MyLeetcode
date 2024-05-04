class Solution {
public:
    int compute(int cnt) {
        if (cnt < 2) return -1;
        if (cnt == 2) return 1;
        if (cnt == 3) return 1;
        return (cnt + 2) / 3;
    }
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& num : nums) mp[num]++;
        int res = 0;
        for (auto& [num, cnt] : mp) {
            int current = compute(cnt);
            if (current == -1) return -1;
            res += current;
        }
        return res;
    }
};
