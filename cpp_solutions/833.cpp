class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, pair<string, string>>> replacements;
        int n = indices.size();
        for (int i = 0; i < n; ++i) {
            replacements.push_back(make_pair(indices[i], make_pair(sources[i], targets[i])));
        }
        sort(replacements.begin(), replacements.end());
        
        int useIndex = 0;
        string res = "";
        
        for (int i = 0; i < s.size(); ++i) {
            // to cache up
            if (useIndex < n && replacements[useIndex].first < i) useIndex++;
            
            bool flag = true;
            if (useIndex < n && i == replacements[useIndex].first) {
                int size = replacements[useIndex].second.first.size();
                if (i + size > s.size()) flag = false;
                for (int j = 0; j < size && flag; ++j) {
                    if (replacements[useIndex].second.first[j] != s[i + j]) flag = false;
                }
            }
            else flag = false;
            
            if (flag) {
                res += replacements[useIndex].second.second;
                i += replacements[useIndex].second.first.size() - 1;
                useIndex++;
            }
            else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};