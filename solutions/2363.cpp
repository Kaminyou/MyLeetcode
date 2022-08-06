class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> value2weight;
        for (auto& item : items1) {
            value2weight[item[0]] += item[1];
        }
        for (auto& item : items2) {
            value2weight[item[0]] += item[1];
        }
        vector<vector<int>> res;
        for (auto& element : value2weight) {
            res.push_back({element.first, element.second});
        }
        return res;
    }
};