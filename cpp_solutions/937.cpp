class Solution {
public:
    static vector<string> log2vector(const string& log) {
        stringstream ss(log);
        string token;
        vector<string> out;
        while (getline(ss, token, ' ')) out.push_back(token);
        return out;
    }
    static bool compare(const string& log1, const string& log2) {
        vector<string> log1v = log2vector(log1);
        vector<string> log2v = log2vector(log2);
        int m = log1v.size();
        int n = log2v.size();
        int k = min(m, n);
        for (int i = 1; i < k; i++) {
            if (log1v[i] != log2v[i]) return log1v[i] < log2v[i];
        }
        if (m != n) return m < n;
        return log1v[0] < log2v[0];
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters;
        vector<string> digits;
        for (auto log : logs) {
            int index = log.find(' ');
            char c = log[index + 1];
            if (c >= '0' && c <= '9') digits.push_back(log);
            else letters.push_back(log);
        }
        sort(letters.begin(), letters.end(), compare);
        
        for (auto log : digits) {
            letters.push_back(log);
        }
        
        return letters;
    }
};