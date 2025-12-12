class Solution {
public:
    static const bool compare(vector<string>& a, vector<string>& b) {
        int aa = stoi(a[1]);
        int bb = stoi(b[1]);
        if (aa == bb) {
            return b[0] == "MESSAGE";
        }
        return aa < bb;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), compare);
        int now = 0;
        queue<pair<int, int>> q;
        unordered_set<int> st;
        unordered_map<int, int> offlineCnt;
        for (int i = 0; i < numberOfUsers; ++i) st.insert(i);
        vector<int> res(numberOfUsers, 0);
        for (auto& event : events) {
            string command = event[0];
            int timestamp = stoi(event[1]);
            string ids = event[2];
            if (command == "OFFLINE") {
                int id = stoi(ids);
                q.push({timestamp + 60, id});
                st.erase(id);
                offlineCnt[id]++;
            }
            else {
                now = timestamp;
                while (q.size() > 0 && q.front().first <= now) {
                    pair<int, int> p = q.front();
                    q.pop();
                    offlineCnt[p.second]--;
                    if (offlineCnt[p.second] == 0) st.insert(p.second);
                }
                if (ids == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) res[i]++;
                }
                else if (ids == "HERE") {
                    for (int i : st) res[i]++;
                }
                else {
                    stringstream ss(ids);
                    string id;
                    while (getline(ss, id, ' ')) {
                        int idInt = stoi(id.substr(2));
                        res[idInt]++;
                    }
                }
            }
        }
        return res;
    }
};
