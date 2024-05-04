class Solution {
public:
    int prefix(string pre) {
        if (pre[0] == '?' && pre[1] == '?') return 24;
        if (pre[0] == '?') {
            if (pre[1] - '0' >= 0 && pre[1] - '0' <= 3) return 3;
            else return 2;
        }
        if (pre[1] == '?') {
            if (pre[0] == '0' || pre[0] == '1') return 10;
            else return 4;
        }
        return 1;
    }
    int suffix(string suf) {
        if (suf[0] == '?' && suf[1] == '?') return 60;
        if (suf[0] == '?') return 6;
        if (suf[1] == '?') return 10;
        return 1;
    }
    int countTime(string time) {
        return prefix(time.substr(0, 2)) * suffix(time.substr(3, 2));
    }
};
// '?0' => 00 10 20 => 3
// '?1' => 01 11 21 => 3
// '?2' => 02 12 22 => 3
// '?3' => 03 13 23 => 3
// '?4' => 04 14 24 => 3
// '?5' => 05 15  => 2
// '?9' => 09 19  => 2
// '0?' -> 10
// '1?' -> 10
// '2?' -> 0, 1, 2, 3 => 4