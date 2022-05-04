class Solution {
public:
    unordered_set<string> st;
    vector<string> res;
    void backtracking(vector<int>& count, string& curr, int& targetSize, string& middle) {
        if (curr.size() == targetSize) {
            if (st.find(curr) == st.end()) {
                string temp = curr;
                reverse(temp.begin(), temp.end());
                string ans = curr + middle + temp;
                res.push_back(ans);
                st.insert(curr);
            }
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) continue;
            count[i]--;
            curr.push_back(static_cast<char>(i + 'a'));
            backtracking(count, curr, targetSize, middle);
            curr.pop_back();
            count[i]++;
        }
    }
    vector<string> generatePalindromes(string s) {
        vector<int> count(26, 0);
        for (auto c : s) count[c - 'a']++;
        
        string middle = "";
        int targetSize = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] & 1) {
                middle.push_back(static_cast<char>(i + 'a'));
                if (middle.size() > 1) return res;
            }
            count[i] /= 2;
            targetSize += count[i];
        }
        string out;
        backtracking(count, out, targetSize, middle);
        return res;
    }
};