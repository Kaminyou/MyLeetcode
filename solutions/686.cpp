class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        string as = a;
        int multiply = 1;
        while (as.size() < m) {
            as += a;
            multiply++;
        }
        if (as.find(b) != string::npos) return multiply;
        as += a;
        if (as.find(b) != string::npos) return multiply + 1;
        return -1;
    }
};