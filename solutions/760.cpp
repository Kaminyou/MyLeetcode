class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, stack<int>> mp;
        int n = nums2.size();
        for (int i = 0; i < n; ++i) {
            mp[nums2[i]].push(i);
        }
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int num = nums1[i];
            res[i] = mp[num].top();
            mp[num].pop();
        }
        return res;
    }
};