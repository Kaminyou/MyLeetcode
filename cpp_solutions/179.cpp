class Solution {
public:
    static bool compare(const string& a, const string& b) {
        string c = a + b;
        string d = b + a;
        return c > d;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> ss;
        bool allZero = true;
        for (auto& num : nums) {
            ss.push_back(to_string(num));
            if (num != 0) allZero = false;
        }
        if (allZero) return "0";
        sort(ss.begin(), ss.end(), compare);
        string res;
        for (auto& s : ss) res += s;
        return res;
    }
};

