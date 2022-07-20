class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        vector<vector<pair<int, int>>> hash(26);
        for (int i = 0; i < words.size(); ++i) {
            auto& word = words[i];
            hash[word[0] - 'a'].push_back(make_pair(i, 1));
        }
        
        for (auto c : s) {
            vector<pair<int, int>> collect;
            for (auto [idx, j] : hash[c - 'a']) {
                if (words[idx].size() == j) count++;
                else if (words[idx][j] == c) {
                    collect.push_back(make_pair(idx, j + 1));
                }
                else hash[words[idx][j] - 'a'].push_back(make_pair(idx, j + 1));
            }
            hash[c - 'a'] = collect;
        }
        return count;
    }
};

// V2
// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         vector<vector<pair<int, int>>> positions(26); // {alphabet}->{{id, position}}
//         int res = 0;
//         for (int i = 0; i < words.size(); ++i) {
//             positions[words[i][0] - 'a'].push_back(make_pair(i, 1));
//         }
        
//         for (int i = 0; i < s.size(); ++i) {
//             auto vec = positions[s[i] - 'a'];
//             positions[s[i] - 'a'].clear();
//             for (auto p : vec) {
//                 if (words[p.first].size() == p.second) res++;
//                 else positions[words[p.first][p.second] - 'a'].push_back(make_pair(p.first, p.second + 1));
//             }
//         }
        
//         return res;
//     }
// };