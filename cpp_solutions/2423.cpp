class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> cnt(26, 0);
        for (auto& c : word) {
            cnt[c - 'a']++;
        }
        unordered_map<int, int> mp;
        int diff = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) {
                mp[cnt[i]]++;
                diff++;
            }
        }
        if (diff == 1) return true;
        if (diff == word.size()) return true;
        if (mp.size() == 1) return false;
        if (mp.size() >= 3) return false;
        vector<pair<int, int>> elements;
        for (auto element : mp) {
            elements.push_back(element);
        }
        sort(elements.begin(), elements.end());
        if (elements[1].first != elements[0].first + 1) return false;
        if (elements[0].second != 1 && elements[1].second != 1) return false;
        return true;
    }
};