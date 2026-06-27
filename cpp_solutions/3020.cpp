class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> mp;
        for (auto num : nums) mp[num] += 1;
        int n = mp.size();
        vector<long long> elements(n, 0);
        int i = 0;
        for (auto& [k, v] : mp) {
            elements[i] = k;
            i++;
        }
        int res = 1;
        for (int i = 0; i < n; ++i) {
            long long element = elements[i];
            if (element == 1) {
                int count = mp[element];
                if (!(count & 1)) count -= 1;
                res = max(res, count);
                continue;
            }
            if (mp[element] == -1) continue;
            if (mp[element] <= 1) {
                continue;
            }
            int curr = 1;
            while (mp.count(element * element)) {
                element = element * element;
                curr++;
                int count = mp[element];
                mp[element] = -1;
                if (count <= 1) break;
            }
            res = max(res, curr * 2 - 1);
        }
        return res;
    }
};
