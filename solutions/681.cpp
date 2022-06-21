class Solution {
public:
    bool isValid(const int hour, const int minute) {
        if (hour >= 24) return false;
        if (hour < 0) return false;
        if (minute >= 60) return false;
        if (minute < 0) return false;
        return true;
    }
    bool isAfter(const int currH, const int currM, const int prevH, const int prevM) {
        if (currH < prevH) return false;
        if (currH == prevH && currM <= prevM) return false;
        return true;
    }
    int getDiff(int currH, int currM, int prevH, int prevM) {
        if (!isAfter(currH, currM, prevH, prevM)) {
            currH += 24;
        }
        if (currM < prevM) {
            currM += 60;
            currH -= 1;
        }
        return (currH - prevH) * 60 + (currM - prevM);
    }
    string nextClosestTime(string time) {
        vector<int> values;
        int hour = -1;
        int minute = -1;
        string token;
        stringstream ss(time);
        while (getline(ss, token, ':')) {
            if (hour == -1) hour = stoi(token);
            else minute = stoi(token);
        }
        for (auto& c : time) {
            if (c != ':') {
                values.push_back(c - '0');
            }
        }
        
        int diff = INT_MAX;
        int hAns = -1;
        int mAns = -1;
        for (auto& currH1 : values) {
            for (auto& currH2 : values) {
                for (auto& currM1 : values) {
                    for (auto& currM2 : values) {
                        int currH = currH1 * 10 + currH2;
                        int currM = currM1 * 10 + currM2;
                        if (isValid(currH, currM)) {
                            int currDiff = getDiff(currH, currM, hour, minute);
                            if (currDiff < diff) {
                                diff = currDiff;
                                hAns = currH;
                                mAns = currM;
                            }
                        }
                    }
                }
            }
        }
        string hStr = to_string(hAns);
        if (hStr.size() == 1) hStr = "0" + hStr;
        string mStr = to_string(mAns);
        if (mStr.size() == 1) mStr = "0" + mStr;
        return hStr + ":" + mStr;
        
    }
};