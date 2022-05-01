class Solution {
public:
    string crackSafe(int n, int k) {
        int count = pow(k, n);
        string res = string(n, '0');
        
        unordered_set<string> hash;
        hash.insert(res);
        
        for (int i = 0; i < count; i++) {
            string prev = res.substr(res.size() - n + 1, n - 1);
            for (int j = k - 1; j >= 0; j--) {
                string curr = prev + to_string(j);
                if (hash.find(curr) == hash.end()) {
                    hash.insert(curr);
                    res.push_back(j + '0');
                    break;
                }
            }
        }
        return res;
    }
};