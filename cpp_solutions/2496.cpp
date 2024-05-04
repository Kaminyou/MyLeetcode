class Solution {
public:
    bool isAllNumber(string& s) {
        for (auto& c : s) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int maxValue = 0;
        for (auto& s : strs){
            if (isAllNumber(s)) {
                int num = stoi(s);
                maxValue = max(maxValue, num);
            }
            else {
                int n = s.size();
                maxValue = max(maxValue, n);
            }
        }
        return maxValue;
    }
};