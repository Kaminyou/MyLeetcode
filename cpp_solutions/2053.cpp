class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto& s : arr) mp[s]++;
        int order = 0;
        for (auto& s : arr) {
            if (mp[s] == 1) {
                mp[s]--;
                order += 1;
                if (order == k) return s;
            }
        }
        return "";
    }
};
