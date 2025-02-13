class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        int n = target.size();
        string current;
        for (int i = 0; i < n; ++i) {
            current.push_back('a');
            res.push_back(current);
            while (current.back() != target[i]) {
                current.back() += 1;
                res.push_back(current);
            }
        }
        return res;
    }
};
