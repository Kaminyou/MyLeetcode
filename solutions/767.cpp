class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> counts(26, 0);
        for (const auto& c : s) {
            counts[c - 'a']++;            
        }
        
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                if (counts[i] > ((n + 1) / 2)) return "";
                pq.push(make_pair(counts[i], i + 'a'));
            }
        }
        
        string res;
        while (pq.size() >= 2) {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            res.push_back(first.second);
            res.push_back(second.second);
            if (first.first - 1 > 0) pq.push(make_pair(first.first - 1, first.second));
            if (second.first - 1 > 0) pq.push(make_pair(second.first - 1, second.second));
        }
        if (!pq.empty()) res.push_back(pq.top().second);
        return res;
    }
};
