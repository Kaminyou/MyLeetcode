class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for (auto& word : words) {
            int sum = 0;
            for (auto& c : word) {
                sum += weights[c - 'a'];
            }
            res.push_back((25 - (sum % 26)) + 'a');
        }
        return res;
    }
};
