class Solution {
public:
    vector<string> res;
    void removeStr(string& s, int count) {
        while (count--) {
            s.pop_back();
        }
    }
    void backtracking(string& num, int currIdx, int target, long long prev, long long sum, string& prevStr) {
        if (currIdx == num.size() && sum == target) {
            res.push_back(prevStr);
            return;
        }
        
        for (int i = 1; currIdx + i <= num.size(); ++i) {
            string extract = num.substr(currIdx, i);
            long long extractLL = stoll(extract);
            
            if (extract.size() > 1 && extract[0] == '0') return;
            if (prevStr.size() != 0) {
                
                int count = 1 + extract.size();
                prevStr += "+" + extract;
                backtracking(num, currIdx + i, target, extractLL, sum + extractLL, prevStr);
                removeStr(prevStr, count);
                
                prevStr += "-" + extract;
                backtracking(num, currIdx + i, target, -extractLL, sum - extractLL, prevStr);
                removeStr(prevStr, count);
                
                prevStr += "*" + extract;
                backtracking(num, currIdx + i, target, prev * extractLL, (sum - prev) + prev * extractLL, prevStr);
                removeStr(prevStr, count);
            }
            else {
                int count = extract.size();
                prevStr += extract;
                backtracking(num, currIdx + i, target, extractLL, extractLL, prevStr);
                removeStr(prevStr, count);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        string prevString = "";
        backtracking(num, 0, target, 0, 0, prevString);
        return res;
    }
};