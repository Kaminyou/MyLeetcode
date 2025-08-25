class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int accum = 0;
        map<int, int> mp;
        mp[-100000] = 0;
        for (auto& fruit : fruits) {
            accum += fruit[1];
            mp[fruit[0]] = accum;
        }
        mp[300000] = accum;
        int res = 0;
        for (int left = startPos - k; left <= startPos; left += 1) {
            int right = max(left + k - (startPos - left), startPos);
            // [left, right]
            auto it = mp.lower_bound(left);
            it--;
            int leftV = it->second;
            it = mp.upper_bound(right);
            it--;
            int rightV = it->second;
            res = max(res, rightV - leftV);
        }
        for (int right = startPos + k; right >= startPos; right -= 1) {
            int left = min(right - (k - (right - startPos)), startPos);
            // [left, right]
            auto it = mp.lower_bound(left);
            it--;
            int leftV = it->second;
            it = mp.upper_bound(right);
            it--;
            int rightV = it->second;
            res = max(res, rightV - leftV);
        }
        return res;
    }
};

