class Solution {
public:
    string formatting(int h, int m) {
        string hStr = to_string(h);
        string mStr = to_string(m);
        if (mStr.size() == 1) mStr = "0" + mStr;
        return hStr + ":" + mStr;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int i = 0; i <= turnedOn; ++i) {
            int hour = i;
            int minute = turnedOn - i;
            if (hour > 4) continue;
            if (minute > 6 || minute < 0) continue;
            
            for (int h = 0; h < 12; ++h) {
                if (!(__builtin_popcount(h) == hour)) continue;
                for (int m = 0; m < 60; ++m) {
                    if (!(__builtin_popcount(m) == minute)) continue;
                    res.push_back(formatting(h, m));
                }
            }
        }
        return res;
    }
};