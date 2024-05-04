class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> mp;
        for (auto num : nums) mp[num]++;
        
        int res = 0;
        for (int i = 0; i < target.size() - 1; i++) {
            string prev = target.substr(0, i + 1);
            string next = target.substr(i + 1);
            int prevVal, nextVal;
            if (mp.find(prev) == mp.end()) continue;
            prevVal = mp[prev];
            if (mp.find(next) == mp.end()) continue;
            nextVal = mp[next];
            if (prev == next) {
                res += (prevVal * (prevVal - 1));
            }
            else res += (prevVal * nextVal);
        }
        return res;
    }
};