class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<short> record(2001, 0);
        vector<bool> visited(2001, false);
        for (auto num : arr) record[num + 1000]++;
        
        for (int i = 0; i < 2001; i++) {
            if (record[i] == 0) continue;
            if (visited[record[i]] == true) return false;
            visited[record[i]] = true;
        }
        return true;
    }
};

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto& num : arr) cnt[num]++;
        
        unordered_set<int> occurence;
        for (auto& [num, appear] : cnt) {
            if (occurence.count(appear)) return false;
            occurence.insert(appear);
        }
        return true;
    }
};