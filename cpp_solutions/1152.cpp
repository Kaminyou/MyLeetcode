class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        unordered_map<string, map<int, string>> mp; // name->{time, web}
        
        int maxFreq = 0;
        unordered_map<string, int> freq;
        
        for (int i = 0; i < n; i++) {
            mp[username[i]][timestamp[i]] = website[i];
        }
        
        for (auto element : mp) {
            map<int, string> userData = element.second;
            unordered_set<string> st;
            for (auto i = userData.begin(); i != userData.end(); i++) {
                for (auto j = next(i); j != userData.end(); j++) {
                    for (auto k = next(j); k != userData.end(); k++) {
                        string hashing = i->second + " " + j->second + " " + k->second;
                        st.insert(hashing);
                    }
                }
            }
            for (auto pattern : st) {
                freq[pattern]++;
                maxFreq = max(maxFreq, freq[pattern]);
            }
        }
        string res = "";
        for (auto element : freq) {
            if (element.second == maxFreq) {
                if (res.size() == 0) res = element.first;
                else if (element.first < res) res = element.first;
            }
        }
        
        string token;
        stringstream ss(res);
        vector<string> ans;
        while (getline(ss, token, ' ')) ans.push_back(token);
        return ans;
    }
};