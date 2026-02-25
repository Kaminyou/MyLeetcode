typedef pair<int, int> P;
class Solution {
public:
    static bool compare(P& p1, P& p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<P> v;
        for (auto& num : arr) {
            int cnt = __builtin_popcount(num);
            v.push_back({cnt, num});
        }

        sort(v.begin(), v.end(), compare);

        vector<int> res;
        for (auto& p : v) {
            res.push_back(p.second);
        }
        return res;
    }
};

class Solution {
public:
    static bool compare(int a, int b) {
        int cA = __builtin_popcount(a);
        int cB = __builtin_popcount(b);
        if (cA == cB) return a < b;
        return cA < cB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
