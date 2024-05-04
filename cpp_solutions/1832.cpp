class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt = 0;
        vector<bool> hash(26, false);
        for (auto& c : sentence) {
            if (hash[c - 'a'] == false) {
                cnt++;
                hash[c - 'a'] = true;
            }
            if (cnt == 26) return true;
        }
        return false;
    }
};