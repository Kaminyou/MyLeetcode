class ValidWordAbbr {
public:
    string toAbbr(string& s) {
        int n = s.size();
        if (n <= 2) return s;
        char first = s[0];
        char last = s[n - 1];
        string middle = to_string(n - 2);
        return first + middle + last;
    }
    unordered_map<string, unordered_set<string>> mp; // abbr->{words}
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto& word : dictionary) {
            mp[toAbbr(word)].insert(word);
        }
    }
    
    bool isUnique(string word) {
        string abbr = toAbbr(word);
        if (mp.find(abbr) == mp.end()) return true;
        if (mp[abbr].find(word) != mp[abbr].end() && mp[abbr].size() == 1) return true;
        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */