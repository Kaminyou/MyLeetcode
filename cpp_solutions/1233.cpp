class Solution {
public:
    vector<string> fold2vec(string& s) {
        vector<string> res;
        string sub = s.substr(1);
        stringstream ss(sub);
        string token;
        while (getline(ss, token, '/')) {
            res.push_back(token);
        }
        return res;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(), folder.end());
        vector<string> prev;
        for (auto& fold : folder) {
            if (res.empty()) {
                res.push_back(fold);
                prev = fold2vec(fold);
            }
            else {
                vector<string> curr = fold2vec(fold);
                int n = min(prev.size(), curr.size());
                bool diff = false;
                for (int i = 0; i < n; ++i) {
                    if (prev[i] != curr[i]) {
                        diff = true;
                        break;
                    }
                }
                if (diff) {
                    res.push_back(fold);
                    prev = curr;
                }
            }
        }
        return res;
    }
};
