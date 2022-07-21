class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = words.size();
        int l = words[0].size();
        if (s.size() < n * l) return res;
        unordered_map<string, int> mp;
        for (auto& word : words) mp[word]++;
        
        for (int i = 0; i <= s.size() - n * l; ++i) {
            unordered_map<string, int> counting;
            int j = 0;
            for (; j < n; ++j) {
                string temp = s.substr(i + j * l, l);
                if (mp.find(temp) == mp.end()) break;
                counting[temp]++;
                if (counting[temp] > mp[temp]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};