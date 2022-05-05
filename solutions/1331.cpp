class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> ranking;
        for (int i = 0; i < arr.size(); i++) ranking.push_back(make_pair(arr[i], i));
        sort(ranking.begin(), ranking.end());
        
        int rank = 1;
        int index = 0;
        while (index < ranking.size()) {
            int curr = ranking[index].first;
            arr[ranking[index].second] = rank;
            while ((index + 1 < ranking.size()) && (ranking[index + 1].first == curr)) {
                index++;
                arr[ranking[index].second] = rank;
            }
            index++;
            rank++;
        }
        return arr;
    }
};