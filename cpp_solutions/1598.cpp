class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (auto& log : logs) {
            if (log == "./") {
                continue;
            }
            if (log == "../") {
                if (cnt > 0) cnt -= 1;
            }
            else {
                cnt += 1;
            }
        }
        return cnt;
    }
};
