class Solution {
public:
    void printHash(vector<int>& hash) {
        for (int i = 0; i < 26; ++i) {
            cout << hash[i] << " ";
        }
        cout << endl;
    }
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        if (m < n) return {};

        vector<int> pHash(26, 0);
        for (auto& c : p) pHash[c - 'a']++;

        vector<int> sHash(26, 0);
        for (int i = 0; i < n - 1; ++i) {
            sHash[s[i] - 'a']++;
        }

        vector<int> res;
        for (int i = n - 1; i < m; ++i) {
            sHash[s[i] - 'a']++;
            bool isSame = true;
            for (int j = 0; j < 26; ++j) {
                if (sHash[j] != pHash[j]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) res.push_back(i - n + 1);
            sHash[s[i - n + 1] - 'a']--;
        }
        return res;
    }
};