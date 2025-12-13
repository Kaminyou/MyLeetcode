class Solution {
public:
    bool isCodeValid(string& code) {
        if (code == "") return false;
        for (auto& c : code) {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_'))) return false;
        }
        return true;
    }
    bool isBusinessValid(string& business) {
        return (business == "electronics" || business == "grocery" || business == "pharmacy" || business == "restaurant");
    }
    static const bool compare(pair<string, char>& p1, pair<string, char>& p2) {
        if (p1.second != p2.second) return p1.second < p2.second;
        return p1.first < p2.first;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, char>> v;
        int n = code.size();
        for (int i = 0; i < n; ++i) {
            if (!isCodeValid(code[i])) continue;
            if (!isBusinessValid(businessLine[i])) continue;
            if (!isActive[i]) continue;
            v.push_back({code[i], businessLine[i][0]});
        }
        sort(v.begin(), v.end(), compare);
        vector<string> res;
        for (auto& vv : v) {
            res.push_back(vv.first);
        }
        return res;
    }
};
