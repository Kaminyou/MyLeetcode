class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (auto& pattern : patterns) {
            int index = word.find(pattern);
            if (index != string::npos) cnt++;
        }
        return cnt;
    }
};
