class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        unordered_map<string, vector<int>> mp;
        int n = words.size();
        for (int i = 0; i < n; ++i) mp[words[i]].push_back(i);
        if (mp.find(target) == mp.end()) return -1;
        
        int ans = INT_MAX;
        for (auto& position : mp[target]) {
            ans = min(ans, abs(startIndex - position));
            ans = min(ans, abs(startIndex + n - position));
            ans = min(ans, abs(position + n - startIndex));
        }
        return ans;
    }
};