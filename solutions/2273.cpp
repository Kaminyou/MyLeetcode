class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string currStr = "";
        vector<string> res;
        for (auto word : words) {
            string temp = word;
            sort(temp.begin(), temp.end());
            if (temp == currStr) continue;
            currStr = temp;
            res.push_back(word);
        }
        return res;
    }
};