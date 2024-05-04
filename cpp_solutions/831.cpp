class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            // email
            int index = s.find('@');
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                s[i] = tolower(s[i]);
            }
            string name = s.substr(0, index);
            string domain = s.substr(index + 1);
            return name.substr(0, 1) + "*****" + name.substr(name.size() - 1) + "@" + domain;
        }
        else {
            string clear;
            for (auto& c : s) {
                if (isdigit(c)) clear.push_back(c);
            }
            reverse(clear.begin(), clear.end());
            string res;
            int n = clear.size();
            res += clear.substr(0, 4);
            res += "-***-***";
            if (n == 11) res += "-*+";
            else if (n == 12) res += "-**+";
            else if (n == 13) res += "-***+";
            reverse(res.begin(), res.end());
            return res;
        }
    }
};