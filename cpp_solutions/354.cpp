class Solution {
public:
    static bool compare(vector<int>& envelope1, vector<int>& envelope2) {
        if (envelope1[0] != envelope2[0]) return envelope1[0] < envelope2[0];
        return envelope1[1] > envelope2[1];
    }
    int binarySearch(vector<int>& res, int target) {
        int left = 0;
        int right = res.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (res[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), compare);
        
        vector<int> res;
        res.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++) {
            if (envelopes[i][1] > res.back()) res.push_back(envelopes[i][1]);
            else {
                int index = binarySearch(res, envelopes[i][1]);
                res[index] = envelopes[i][1];
            }
        }
        return res.size();
    }
};