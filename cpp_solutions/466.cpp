class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int length1 = s1.size();
        int length2 = s2.size();
        int total1 = length1 * n1;
        int idx1 = 0;
        int idx2 = 0;
        map<pair<int, int>, pair<int, int>> mp;
        while (idx1 < total1) {
            if (s1[idx1 % length1] == s2[idx2 % length2]) {
                if (mp.find(make_pair(idx1 % length1, idx2 % length2)) != mp.end()) {
                    auto [prev1, prev2] = mp[{idx1 % length1, idx2 % length2}];
                    int cycle1 = idx1 - prev1;
                    int cycle2 = idx2 - prev2;
                    int repeat1 = (total1 - idx1) / cycle1;
                    idx1 += repeat1 * cycle1;
                    idx2 += repeat1 * cycle2;
                    if (idx1 >= total1) break;
                }
                else {
                    mp[{idx1 % length1, idx2 % length2}] = make_pair(idx1, idx2);
                }
                idx2++;
            }
            idx1++;
        }
        
        return idx2 / length2 / n2;
    }
};
