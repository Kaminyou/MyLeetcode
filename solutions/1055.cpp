class Solution {
public:
    int shortestWay(string source, string target) {
        int count = 1;
        int flag = 0;
        int sourceIdx = 0;
        int targetIdx = 0;
        while (targetIdx < target.size()) {
            if (source[sourceIdx] == target[targetIdx]) {
                targetIdx++;
                sourceIdx++;
                flag = 0;
            }
            else {
                sourceIdx++;
                flag++;
                if (flag == source.size()) return -1;
            }
            if (sourceIdx == source.size() && targetIdx < target.size()) {
                sourceIdx = 0;
                count++;
            }
        }
        return count;
    }
};