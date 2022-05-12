class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); i++) mp[list1[i]] = i;
        
        vector<string> res;
        int minVal = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (mp.find(list2[i]) != mp.end()) {
                if (i + mp[list2[i]] < minVal) {
                    minVal = i + mp[list2[i]];
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if (i + mp[list2[i]] == minVal) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};