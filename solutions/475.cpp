class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for (auto& house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house); // >=
            int index = it - heaters.begin();
            if (index < heaters.size() && heaters[index] == house) continue;
            int distance = INT_MAX;
            if (index != heaters.size()) distance = min(distance, heaters[index] - house);
            if (index != 0) distance = min(distance, house - heaters[index - 1]);
            res = max(res, distance);
        }
        return res;
    }
};