class Solution {
public:
    int getLength(vector<int>& nums) {
        unordered_map<int, int> counts;
        int res = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int left = 0; left < n; ++left) {
            counts.clear();
            mp.clear();
            for (int right = left; right < n; ++right) {
                int oldCnt = counts[nums[right]];
                counts[nums[right]] += 1;
                int newCnt = counts[nums[right]];
                if (oldCnt != 0) {
                    mp[oldCnt]--;
                    if (mp[oldCnt] == 0) mp.erase(oldCnt);
                }
                mp[newCnt]++;
                if (mp.size() == 1) {
                    int cnt = mp.begin()->second;
                    if (cnt == 1) res = max(res, right - left + 1);
                }
                if (mp.size() == 2) {
                    int cnt1 = mp.begin()->first;
                    int cnt2 = next(mp.begin())->first;
                    if (cnt1 > cnt2) swap(cnt1, cnt2);
                    if (cnt1 * 2 == cnt2) res = max(res, right - left + 1);
                }
            }
        }
        return res;
    }
};

