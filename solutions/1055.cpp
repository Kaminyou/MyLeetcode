class Solution {
public:
    int shortestWay(string source, string target) {
        int m = source.size();
        int n = target.size();
        int sourceIdx = 0;
        int targetIdx = 0;
        int penalty = 0;
        int count = 1;
        while (targetIdx < n) {
            if (source[sourceIdx] == target[targetIdx]) {
                sourceIdx++;
                targetIdx++;
                penalty = 0;
            }
            else {
                sourceIdx++;
                penalty++;
            }
            if (penalty == m) return -1;
            if (sourceIdx == m && targetIdx < n) {
                sourceIdx = 0;
                count++;
            }
        }
        return count;
    }
};