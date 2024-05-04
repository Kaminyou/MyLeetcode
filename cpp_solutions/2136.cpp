class Solution {
public:
    static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first) return p1.second > p2.second;
        return p1.first > p2.first;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> growWithPlant(n);
        for (int i = 0; i < n; ++i) {
            growWithPlant[i].first = growTime[i];
            growWithPlant[i].second = plantTime[i];
        }
        
        sort(growWithPlant.begin(), growWithPlant.end(), cmp);
        int res = 0;
        int plantSum = 0;
        for (int i = 0; i < n; ++i) {
            plantSum += growWithPlant[i].second;
            res = max(res, plantSum + growWithPlant[i].first);
        }
        return res;
    }
};