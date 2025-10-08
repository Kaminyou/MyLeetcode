class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> res(n, 0);
        
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; ++i) {
            long long curr = spells[i];
            int left = 0;
            int right = potions.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if ((long long)potions[mid] * curr >= success) right = mid;
                else left = mid + 1;
            }
            res[i] = m - left;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {spells[i], i};
        }
        sort(v.begin(), v.end());
        sort(potions.begin(), potions.end());
        vector<int> res(n, 0);
        int spellIdx = 0;
        int potionIdx = m;
        for (int i = 0; i < n; ++i) {
            long long spell = v[i].first;
            while (potionIdx - 1 >= 0 && (long long)potions[potionIdx - 1] * spell >= success) {
                potionIdx--;
            }
            res[v[i].second] = m - potionIdx;
        }
        return res;
    }
};
