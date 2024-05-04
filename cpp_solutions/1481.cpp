class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto& num : arr) {
            mp[num]++;
        }
        vector<int> cnts;
        for (auto& [num, cnt] : mp) cnts.push_back(cnt);
        sort(cnts.begin(), cnts.end());
        int n = cnts.size();
        int index = 0;
        while (index < n && k >= cnts[index]) {
            k -= cnts[index];
            index++;
        }
        return n - index;
    }
};
