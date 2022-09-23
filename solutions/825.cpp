class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int res = 0;
        int left = -1;
        int right = -1;
        for (auto& age : ages) {
            while (right + 1 < n && ages[right + 1] <= age) right++;
            while (left + 1 < n && (double)ages[left + 1] <= 0.5 * (double)age + 7) left++;
            res += max(0, (right - left - 1));
        }
        return res;
    }
};