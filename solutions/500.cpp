class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string firstRow = "qwertyuiopQWERTYUIOP";
        string secondRow = "asdfghjklASDFGHJKL";
        string thirdRow = "zxcvbnmZXCVBNM";
        vector<int> hash(256, -1);
        for (auto c : firstRow) hash[c] = 0;
        for (auto c : secondRow) hash[c] = 1;
        for (auto c : thirdRow) hash[c] = 2;
        
        vector<string> res;
        for (auto word : words) {
            vector<int> curr(3, 0);
            for (auto c : word) {
                curr[hash[c]]++;
            }
            if ((curr[0] == 0 && curr[1] == 0) || (curr[1] == 0 && curr[2] == 0) || (curr[0] == 0 && curr[2] == 0)) res.push_back(word);
        }
        return res;
    }
};