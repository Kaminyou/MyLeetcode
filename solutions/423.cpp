class Solution {
public:
    int haveChar(vector<int>& count, char c) {
        return count[c - 'a'];
    }
    void reduceCount(vector<int>& count, string s, int reduce) {
        for (auto& c : s) {
            count[c - 'a'] -= reduce;
        }
    }
    string originalDigits(string s) {
        vector<int> countNum(10, 0);
        vector<int> count(26, 0);
        vector<pair<char, pair<string, int>>> order = {{'z',{"zero", 0}}, {'w',{"two", 2}}, 
                                                      {'x',{"six", 6}}, {'g',{"eight", 8}},
                                                      {'u',{"four", 4}}, {'h',{"three", 3}},
                                                      {'f',{"five", 5}}, {'v',{"seven", 7}},
                                                      {'i',{"nine", 9}}, {'o',{"one", 1}}};
        for (auto& c : s) {
            count[c - 'a']++;
        }
        for (auto& [c, element] : order) {
            auto& [s, num] = element;
            int cnt = haveChar(count, c);
            if (cnt) {
                countNum[num] += cnt;
                reduceCount(count, s, cnt);
            }
        }
        string res = "";
        for (int i = 0; i < 10; ++i) {
            res += string(countNum[i], i + '0');
        }
        return res;
    }
};
// zero (z) -> two (w) -> six (x) -> eight (g) -> four (u) -> three (h) -> five (f) ->
// seven (v) -> nine (i) -> one(o)