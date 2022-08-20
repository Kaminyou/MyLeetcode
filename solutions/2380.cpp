class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zeroes = 0;
        int steps = 0;
        for (auto c : s) {
            if (c == '0') {
                zeroes++;
                continue;
            }
            
            if (zeroes) {
                steps = max(steps + 1, zeroes);
            }
        }
        return steps;
    }
};

// V2
// class Solution {
// public:
//     // "01" -> "10"
//     int move(string& s) {
//         int n = s.size();
//         vector<int> res;
//         int index = 0;
//         int count = 0;
//         while (index < n) {
//             if (index + 1 < n && s[index] == '0' && s[index + 1] == '1') {
//                 s[index] = '1';
//                 s[index + 1] = '0';
//                 index += 2;
//                 count++;
//             }
//             else index++;
//         }
//         return count;
//     }
//     int secondsToRemoveOccurrences(string s) {
//         if (s.size() == 1) return 0;
//         int res = 0;
        
//         while (move(s) != 0) {
//             res++;
//         }
//         return res;
//     }
// };
