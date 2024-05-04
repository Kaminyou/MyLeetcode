class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        // create a hash map to check
        // if char in s can be transformed from char in sub
        // in O(1) time
        // hashmap: char in sub -> {chars in s} (use unordered_set as one map to many)
        unordered_map<char, unordered_set<char>> hashmap;
        for (auto& mapping : mappings) {
            hashmap[mapping[0]].insert(mapping[1]);
        }
        
        int m = s.size();
        int n = sub.size();
        for (int i = 0; i <= m - n; ++i) {
            // check each chunk of size n equal to sub
            bool found = true;
            for (int j = 0; j < n; ++j) {
                char to = s[i + j];
                char from = sub[j];
                // if aleady equal, continue
                if (from == to) continue;
                // if not, check by the hash map
                if (hashmap[from].find(to) == hashmap[from].end()) {
                    found = false;
                    break;
                }
            }
            // if there is one chunk in s matching the sub
            // return true
            if (found) return true;
        }
        return false;
    }
};