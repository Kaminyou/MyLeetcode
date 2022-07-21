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