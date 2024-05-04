class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for (auto c : s) {
            mp[c]++;
        }
        for (auto& [c, cnt] : mp) {
            pq.push(make_pair(cnt, c));
        }
        
        string res = "";
        int n = s.size();
        while (!pq.empty()) {
            int size = min(n, k);
            vector<pair<int, char>> v;
            while (size) {
                if (pq.empty()) return "";
                auto [cnt, c] = pq.top();
                pq.pop();
                res.push_back(c);
                if (cnt - 1 > 0) {
                    v.push_back(make_pair(cnt - 1, c));
                }
                size--;
                n--;
            }
            for (auto p : v) pq.push(p);
        }
        return res;
    }
};