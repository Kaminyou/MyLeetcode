class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, unordered_set<string>> hashMap;
        for (auto& idea : ideas) {
            hashMap[idea[0]].insert(idea.substr(1));
        }
        long long res = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                char a = i + 'a';
                char b = j + 'a';
                auto& setA = hashMap[a];
                auto& setB = hashMap[b];
                int intersect = 0;
                for (auto& s : setA) {
                    if (setB.find(s) != setB.end()) intersect++;
                }
                int setADiff = setA.size() - intersect;
                int setBDiff = setB.size() - intersect;
                res += (long long)setADiff * setBDiff * 2;
            }
        }
        return res;
    }
};