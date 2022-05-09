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