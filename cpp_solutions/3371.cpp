class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        int res = INT_MIN;
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            sum += num;
            mp[num]++;
        }
        for (auto& num : nums) {
            if ((sum - num) & 1) continue;
            int half = (sum - num) / 2;
            if (half == num) {
                if (mp[half] >= 2) res = max(res, num);
            }
            else {
                if (mp[half] >= 1) res = max(res, num);
            }
        }
        return res;
    }
};
