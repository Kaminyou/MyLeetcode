class Solution {
public:
    int partitionString(string s) {
        vector<bool> hash(26, false);
        int res = 1;
        for (auto& c : s) {
            if (hash[c - 'a'] == true) {
                res++;
                for (int i = 0; i < 26; ++i) hash[i] = false;
            }
            hash[c - 'a'] = true;
        }
        return res;
    }
};