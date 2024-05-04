class Solution {
public:
    static bool compare(const pair<int, int> p1, const pair<int, int> p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& num : nums) mp[num]++;
        
        // freq, value
        vector<pair<int, int>> v;
        for (auto& element : mp) {
            v.push_back(make_pair(element.second, element.first));
        }
        
        sort(v.begin(), v.end(), compare);
        int index = 0;
        for (auto& [freq, value] : v) {
            for (int i = 0; i < freq; ++i) {
                nums[index] = value;
                index++;
            }
        }
        return nums;
    }
};