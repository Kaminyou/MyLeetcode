class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> rain2day;
        set<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                if (!rain2day.count(rains[i])) {
                    rain2day[rains[i]] = i;
                }
                else {
                    int prev = rain2day[rains[i]];
                    auto it = st.upper_bound(prev);
                    if (it == st.end()) return {};
                    res[*it] = rains[i];
                    st.erase(it);
                    rain2day[rains[i]] = i;
                }
            }
            else {
                st.insert(i);
            }
        }
        for (auto& num : st) res[num] = 1;
        return res;
    }
};

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> rain2idx;
        for (int i = 0; i < n; ++i) {
            mp[rains[i]].push_back(i);
            rain2idx[rains[i]] = 0;
        }
        vector<int> res(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int rain = rains[i];
                int index = rain2idx[rain];
                // has next index
                if (index + 1 < mp[rain].size()) {
                    pq.push({mp[rain][index + 1], rain});
                    rain2idx[rain]++;
                }
            }
            else {
                if (!pq.empty()) {
                    auto [index, rain] = pq.top();
                    pq.pop();
                    if (i > index) return {};
                    res[i] = rain;
                }
                else {
                    res[i] = 1;
                }
            }
        }
        if (!pq.empty()) {
            return {};
        }
        return res;
};

