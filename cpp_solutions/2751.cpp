class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        unordered_map<int, int> pos2idx;
        vector<tuple<int, int, char>> combined;
        for (int i = 0; i < n; ++i) {
            combined.push_back(make_tuple(positions[i], healths[i], directions[i]));
            pos2idx[positions[i]] = i;
        }
        sort(combined.begin(), combined.end());

        stack<tuple<int, int, char>> st;
        for (int i = 0; i < n; ++i) {
            auto [pos, health, dir] = combined[i];
            if (dir == 'R') {
                st.push(make_tuple(pos, health, dir));
            }
            else if (st.empty() || get<2>(st.top()) == 'L') {
                st.push(make_tuple(pos, health, dir));
            }
            else {
                bool canPush = true;
                while (!st.empty() && get<2>(st.top()) == 'R') {
                    auto [topPos, topHealth, topDir] = st.top();
                    st.pop();
                    if (topHealth == health) {
                        canPush = false;
                        break;
                    }
                    if (topHealth > health) {
                        canPush = false;
                        st.push(make_tuple(topPos, topHealth - 1, topDir));
                        break;
                    }
                    else {
                        health -= 1;
                    }
                }
                if (canPush) st.push(make_tuple(pos, health, dir));
            }
        }
        vector<pair<int, int>> temp;
        while (!st.empty()) {
            auto [topPos, topHealth, topDir] = st.top();
            st.pop();
            temp.push_back({pos2idx[topPos], topHealth});
        }
        sort(temp.begin(), temp.end());
        vector<int> res;
        for (auto& [idx, health] : temp) {
            res.push_back(health);
        }
        return res;
    }
};
