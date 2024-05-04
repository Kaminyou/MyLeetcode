class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int index = 0;
        int n = path.size();
        stringstream ss(path);
        string s;
        while (getline(ss, s, '/')) {
            if (s == ".") continue;
            if (s == "..") {
                if (!v.empty()) v.pop_back();
            }
            else if (!s.empty()) {
                v.push_back(s);
            }
        }
        string out;
        for (auto s : v) {
            out += "/";
            out += s;
        }
        if (out.empty()) return "/";
        return out;
    }
};