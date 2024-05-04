class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rQ;
        queue<int> dQ;
        int n = senate.size();
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') rQ.push(i);
            else dQ.push(i);
        }
        while (!rQ.empty() && !dQ.empty()) {
            int rF = rQ.front();
            int dF = dQ.front();
            rQ.pop();
            dQ.pop();
            if (rF < dF) rQ.push(n + rF);
            else dQ.push(n + dF);
        }
        return rQ.empty() ? "Dire" : "Radiant";
    }
};