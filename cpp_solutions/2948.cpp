class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        int index = 0;
        vector<pair<int, int>> groups;
        for (int i = 0; i < n; ++i) {
            groups.push_back({nums[i], i});
        }
        sort(groups.begin(), groups.end());
        while (index < n) {
            int current = index;
            int low = groups[current].first - limit;
            int high = groups[current].first + limit;
            while (index + 1 < n && groups[index + 1].first >= low && groups[index + 1].first <= high) {
                index++;
                low = min(low, groups[index].first - limit);
                high = max(high, groups[index].first + limit);
            }
            // sort within group
            vector<int> indices;
            for (int j = current; j <= index; ++j) {
                indices.push_back(groups[j].second);
            }
            sort(indices.begin(), indices.end());
            for (int j = current; j <= index; ++j) {
                nums[indices[j - current]] = groups[j].first;
            }
            index++;
        }
        return nums;
    }
};
