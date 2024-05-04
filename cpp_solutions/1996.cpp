class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        if (v1[0] == v2[0]) {
            return v1[1] < v2[1];
        }
        return v1[0] > v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), compare);
        int count = 0;
        int maxDefense = 0;
        for (auto& property : properties) {
            if (property[1] < maxDefense) count++;
            else maxDefense = property[1];
        }
        return count;
    }
};