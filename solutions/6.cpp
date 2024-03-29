class Solution {
public:
    int modifyLoopIdx(int loopIdx, int numRows) {
        if (loopIdx >= numRows) {
            return numRows * 2 - 2 - loopIdx;
        }
        return loopIdx;
    }
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> zigzag(numRows, "");
        int loop = numRows * 2 - 2;
        
        int loopIndex = 0;
        for (auto c : s) {
            zigzag[modifyLoopIdx(loopIndex, numRows)].push_back(c);
            loopIndex++;
            if (loopIndex == loop) loopIndex = 0;
        }
        
        string res;
        for (auto& str : zigzag) res += str;
        return res;
    }
};

// v2
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.size();
        int cycle = (numRows - 1) * 2;

        string out;
        for (int i = 0; i < numRows; ++i) {
            int start = i;
            if (start == 0 || start == numRows - 1) {
                while (start < n) {
                    out.push_back(s[start]);
                    start += cycle;
                }
            }
            else {
                int counter = cycle - start;
                while (start < n || counter < n) {
                    if (start < n) out.push_back(s[start]);
                    if (counter < n) out.push_back(s[counter]);
                    start += cycle;
                    counter += cycle;
                }
            }
        }
        return out;
    }
};