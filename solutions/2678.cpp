class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (auto& detail : details) {
            string age = detail.substr(11, 2);
            int ageInt = stoi(age);
            if (ageInt > 60) count++;
        }
        return count;
    }
};