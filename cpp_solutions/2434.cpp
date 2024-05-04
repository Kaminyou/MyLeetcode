class Solution {
public:
    int minFreq(vector<int>& freq) {
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) return i;
        }
        return 0;
    }
    string robotWithString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (auto& c : s) freq[c - 'a']++;
        stack<int> st;
        string res; 
        for (auto& c : s) {
            st.push(c - 'a');
            freq[c - 'a']--;
            while (!st.empty() && st.top() <= minFreq(freq)) {
                res.push_back(st.top() + 'a');
                st.pop();
            }
        }
        while (!st.empty()) {
            res.push_back(st.top() + 'a');
            st.pop();
        }
        return res;
    }
};
