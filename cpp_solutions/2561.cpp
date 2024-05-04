class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int minVal = INT_MAX;
        long long res = 0;
        map<int, int> mp;
        map<int, int> mp1;
        for (auto& num : basket1) {
            mp[num]++;
            mp1[num]++;
            minVal = min(minVal, num);
        }
        for (auto& num : basket2) {
            mp[num]++;
            minVal = min(minVal, num);
        }
        for (auto& [num, c] : mp) {
            if (c & 1) return -1;
        }
        vector<int> more;
        vector<int> less;
        for (auto& [num, c] : mp) {
            int count = c / 2 - mp1[num];
            if (count == 0) continue;
            if (count > 0) {
                for (int i = 0; i < abs(count); ++i) less.push_back(num);
            }
            else {
                for (int i = 0; i < abs(count); ++i) more.push_back(num);
            }
        }
        int n = less.size();
        int lessIdx = 0;
        int moreIdx = 0;
        while (n--) {
            if (more[moreIdx] < less[lessIdx]) {
                if (more[moreIdx] == minVal) {
                    res += more[moreIdx];
                }
                else {
                    res += min(more[moreIdx], minVal * 2);
                }
                moreIdx++;
            }
            else {
                if (less[lessIdx] == minVal) {
                    res += less[lessIdx];
                }
                else {
                    res += min(less[lessIdx], minVal * 2);
                }
                lessIdx++;
            }
        }
        return res;
    }
};
