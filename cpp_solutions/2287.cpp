class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> counts(26, 0);
        for (auto c : s) counts[c - 'a']++;
        
        int times = 0;
        while (true) {
            bool flag = false;
            for (auto c : target) {
                if (counts[c - 'a'] == 0) {
                    flag = true;
                    break;
                }
                counts[c - 'a']--;
            }
            if (flag) break;
            else times++;
        }
        return times;
    }
};