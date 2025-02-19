class Solution {
public:
    priority_queue<string> pq;
    vector<char> chars = {'a', 'b', 'c'};
    void backtracking(int n, int k, string& s) {
        if (s.size() == n) {
            pq.push(s);
            if (pq.size() > k) pq.pop();
        }
        else {
            if (s.size() == 0) {
                for (auto ch : chars) {
                    s.push_back(ch);
                    backtracking(n, k, s);
                    s.pop_back();
                }
            }
            else {
                for (auto ch : chars) {
                    if (s.back() == ch) continue;
                    s.push_back(ch);
                    backtracking(n, k, s);
                    s.pop_back();
                }
            }
        }
    }
    string getHappyString(int n, int k) {
        string s = "";
        backtracking(n, k, s);
        return pq.size() < k ? "" : pq.top();
    }
};
