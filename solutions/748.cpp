class Solution {
public:
    bool isValid(vector<int> hash, int count, string& word) {
        for (auto c : word) {
            c -= 'a';
            if (hash[c] > 0) {
                hash[c]--;
                count--;
            }
        }
        return count == 0;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> hash(26, 0);
        int count = 0;
        for (auto& c : licensePlate) {
            if (c == ' ') continue;
            if (c >= '0' && c <= '9') continue;
            if (c >= 'A' && c <= 'Z') c -= 'A';
            else if (c >= 'a' && c <= 'z') c -= 'a';
            hash[c]++;
            count++;
        }
        string res;
        for (auto& word : words) {
            if (isValid(hash, count, word)) {
                if (res.size() == 0 || word.size() < res.size()) {
                    res = word;
                }
            }
        }
        return res;
    }
};