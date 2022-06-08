class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const int mod = 1e9 + 7;
        int n = hats.size();
        vector<int> states(1 << n, 0);
        states[0] = 1;
        vector<vector<int>> hat2people(40);
        
        for (int i = 0; i < n; ++i) {
            for (auto& hat : hats[i]) {
                hat2people[hat - 1].push_back(i);
            }
        }
        
        for (int i = 0; i < 40; ++i) {
            if (hat2people[i].size() == 0) continue;
            for (int state = (1 << n) - 1; state >= 0; --state) {
                for (auto& k : hat2people[i]) {
                    if ((state & (1 << k)) == 0) {
                        states[state | (1 << k)] += states[state];
                        states[state | (1 << k)] %= mod;
                    }
                }
            }
        }
        
        return states[(1 << n) - 1];
    }
};