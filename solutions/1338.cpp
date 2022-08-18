class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (auto& num : arr) mp[num]++;
        vector<pair<int, int>> cnt2num;
        for (auto& element : mp) {
            cnt2num.push_back(make_pair(element.second, element.first));
        }
        sort(cnt2num.begin(), cnt2num.end(), greater<pair<int, int>>());
        int size = n;
        int count = 0;
        int index = 0;
        while (size > n / 2) {
            size -= cnt2num[index].first;
            count++;
            index++;
        }
        return count;
    }
};

// min(chosen number) -> left one <= half