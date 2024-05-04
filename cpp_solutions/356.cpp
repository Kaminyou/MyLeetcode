class Solution {
public:
    double getMiddleLine(map<int, int>& xMap) {
        int n = xMap.size();
        if (n == 1) return xMap.begin()->first;
        vector<pair<double, int>> xV;
        for (auto& [num, cnt] : xMap) xV.push_back(make_pair(num, cnt));
        
        int left = 1;
        int right = n - 2;
        double middle = (xV[0].first + xV[n - 1].first) / 2;
        while (left <= right) {
            double m = (xV[left].first + xV[right].first) / 2;
            if (m != middle) return INT_MAX;
            left++;
            right--;
        }
        
        return middle;
    }
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, map<int, int>> mp;
        for (auto& point : points) {
            mp[point[1]][point[0]]++;
        }
        
        double line = INT_MAX;
        for (auto& [y, xMap] : mp) {
            if (line == INT_MAX) {
                double middle = getMiddleLine(xMap);
                if (middle == INT_MAX) return false;
                line = middle;
                continue;
            }
            if (line != getMiddleLine(xMap)) return false;
        }
        return true;
    }
};