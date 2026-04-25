class Solution {
public:
    vector<long long> locations;
    int next[15001];
    long long side;
    int n;
    long long pos(int idx) {
        if (idx < n) {
            return locations[idx];
        }
        else {
            return locations[idx % n] + 4 * side;
        }
    }
    bool valid(int minDistance, int k) {
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (pos(j) - pos(i) < minDistance) j++;
            next[i] = j;
        }
        for (int i = 0; i < n; ++i) {
            bool feasible = true;
            int cur = i;
            for (int t = 0; t < k - 1; ++t) {
                if (cur < n) cur = next[cur];
                else cur = next[cur % n] + n;
                if (cur >= i + n) {
                    feasible = false;
                    break;
                }
            }
            if (pos(i) - pos(cur % n) < minDistance) feasible = false;
            if (feasible) return true;
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        this->n = points.size();
        this->side = side;
        for (auto& point : points) {
            if (point[0] == 0) {
                locations.push_back(point[1]);
            }
            else if (point[1] == side) {
                locations.push_back(point[0] + side);
            }
            else if (point[0] == side) {
                locations.push_back(side - point[1] + side * 2LL);
            }
            else if (point[1] == 0) {
                locations.push_back(side - point[0] + side * 3LL);
            }
        }
        sort(locations.begin(), locations.end());
        int left = 0;
        int right = side + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!valid(mid, k)) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};

