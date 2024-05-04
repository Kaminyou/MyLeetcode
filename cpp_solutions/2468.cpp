class Solution {
public:
    int digits(int n) {
        int cnt = 0;
        while (n) {
            n /= 10;
            cnt++;
        }
        return cnt;
    }
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        for (int length = 1; length * 2 + 3 < limit; ++length) {
            int cnt = (pow(10, length) - 1);
            int available = cnt * limit;
            available -= 3 * cnt;
            available -= length * cnt;
            for (int i = 1; i <= length; ++i) {
                available -= i * (pow(10, i) - pow(10, i - 1));
            }
            if (available >= n) return generate(message, limit, length);
        }
        
        return {};
    }
    vector<string> generate(string& message, int limit, int length) {
        int n = message.size();
        vector<string> res;
        int index = 0;
        int cnt = 1;
        while (index < n) {
            int remain = limit - 3;
            remain -= digits(cnt);
            remain -= length;
            int extract = min(remain, n - index);
            string temp = message.substr(index, extract) + "<" + to_string(cnt) + "/";
            res.push_back(temp);
            index += extract;
            cnt++;
        }
        string blockCnt = to_string(cnt - 1);
        for (auto& word : res) {
            word += blockCnt + ">";
        }
        return res;
    }
};

// class Solution {
// public:
//     int digits(int n) {
//         int cnt = 0;
//         while (n) {
//             n /= 10;
//             cnt++;
//         }
//         return cnt;
//     }
//     bool criteria(int block, int n, int limit) {
//         // len n split into # of block with limit
//         int blockCnt = digits(block);
//         int cnt = 0;
//         int index = 1;
//         while (n > 0) {
//             int left = limit - 3;
//             left -= blockCnt;
//             left -= digits(index);
//             if (left <= 0) return false;
//             n -= left;
//             index++;
//             cnt++;
//         }
//         return cnt <= block;
//     }
//     vector<string> splitMessage(string message, int limit) {
//         int left = 1;
//         int right = message.size() + 1;
//         int n = message.size();
//         while (left < right) {
            
//             int mid = left + (right - left) / 2;
//             if (criteria(mid, n, limit)) right = mid;
//             else left = mid + 1;
//         }
//         if (left == message.size() + 1) return {};
        
//         // split into # of left blocks
//         vector<string> res;
//         string blockCnt = to_string(left);
//         int index = 0;
//         int cnt = 1;
//         while (index < n) {
//             int remain = limit - 3;
//             remain -= digits(cnt);
//             remain -= blockCnt.size();
//             int extract = min(remain, n - index);
//             string temp = message.substr(index, extract) + "<" + to_string(cnt) + "/" + blockCnt + ">";
//             res.push_back(temp);
//             index += extract;
//             cnt++;
//         }
//         return res;
//     }
// };
