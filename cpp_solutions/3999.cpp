class Solution {
public:
    int _boothsAlgorithm(std::string s) {
        int n = s.length();
        s += s; 
        std::vector<int> f(s.length(), -1); 
        int k = 0;
        
        for (int j = 1; j < s.length(); ++j) {
            char sj = s[j];
            int i = f[j - k - 1];
            
            while (i != -1 && sj != s[k + i + 1]) {
                if (sj < s[k + i + 1]) {
                    k = j - i - 1;
                }
                i = f[i];
            }
            
            if (sj != s[k + i + 1]) {
                if (sj < s[k]) {
                    k = j;
                }
                f[j - k] = -1;
            } else {
                f[j - k] = i + 1;
            }
        }
        
        return k;
    }
    string boothsAlgorithm(string s) {
        int min_idx = _boothsAlgorithm(s);
        return s.substr(min_idx) + s.substr(0, min_idx);
    }
    string parseWord(string& word) {
        int n = word.size();
        string odd;
        string even;
        for (int i = 0; i < n; ++i) {
            if (i & 1) odd.push_back(word[i]);
            else even.push_back(word[i]);
        }
        odd = boothsAlgorithm(odd);
        even = boothsAlgorithm(even);
        return to_string(n) + "+" + odd + "+" + even;
    }
    int minimumGroups(vector<string>& words) {
        // hash num+odd+even
        unordered_set<string> st;
        for (auto& word : words) {
            string ww = parseWord(word);
            st.insert(ww);
        }
        return st.size();
    }
};


