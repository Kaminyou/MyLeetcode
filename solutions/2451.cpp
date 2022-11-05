class Solution {
public:
    bool isSame(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        for (int i = 0; i < n; ++i) {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }
    string oddString(vector<string>& words) {
        int m = words.size();
        vector<pair<vector<int>, int>> diffArr;
        for (int j = 0; j < m; ++j) {
            string word = words[j];
            int n = word.size();
            vector<int> diffSub;
            for (int i = 0; i < n - 1; ++i) {
                int diff = word[i + 1] - word[i];
                diffSub.push_back(diff);
            }
            diffArr.push_back({diffSub, j});
        }
        
        sort(diffArr.begin(), diffArr.end());
        if (!isSame(diffArr[0].first, diffArr[1].first)) {
            return words[diffArr[0].second];
        }
        else {
            return words[diffArr[diffArr.size() - 1].second];
        }
    }
};