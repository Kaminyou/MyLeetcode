class Solution {
public:
    bool isNumber(string s) {
        bool signFlag = false;
        bool pointFlag = false;
        int beforePointCount = 0;
        int afterPointCount = 0;
        bool eFlag = false;
        bool signEFlag = false;
        int eIntCount = 0;
        for (auto& c : s) {
            if (!eFlag && (c == '+' || c == '-')) {
                if (beforePointCount || pointFlag) return false;
                if (signFlag) return false;
                signFlag = true;
            }
            else if (!eFlag && (c == '.')) {
                if (pointFlag) return false;
                pointFlag = true;
            }
            else if (c == 'E' || c == 'e') {
                if (eFlag) return false;
                eFlag = true;
                if (!pointFlag) {
                    if (!beforePointCount) return false;
                }
                else {
                    if (!beforePointCount && !afterPointCount) return false;
                }
            }
            else if (eFlag && (c == '+' || c == '-')) {
                if (eIntCount) return false;
                if (signEFlag) return false;
                signEFlag = true;
            }
            else if (eFlag && c == '.') return false;
            else if (c >= '0' && c <= '9') {
                if (!eFlag && !pointFlag) beforePointCount++;
                else if (!eFlag && pointFlag) afterPointCount++;
                else eIntCount++;
            }
            else return false;
        }
        if (!eFlag) {
            if (!pointFlag) return beforePointCount != 0;
            else return (beforePointCount != 0) || (afterPointCount != 0);
        } 
        return (eIntCount != 0);
    }
};