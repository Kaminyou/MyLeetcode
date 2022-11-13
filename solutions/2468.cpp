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
    bool criteria(int block, int n, int limit) {
        // len n split into # of block with limit
        int blockCnt = digits(block);
        int cnt = 0;
        int index = 1;
        while (n > 0) {
            int left = limit - 3;
            left -= blockCnt;
            left -= digits(index);
            if (left <= 0) return false;
            n -= left;
            index++;
            cnt++;
        }
        return cnt <= block;
    }
    vector<string> splitMessage(string message, int limit) {
        int left = 1;
        int right = message.size() + 1;
        int n = message.size();
        while (left < right) {
            
            int mid = left + (right - left) / 2;
            if (criteria(mid, n, limit)) right = mid;
            else left = mid + 1;
        }
        if (left == message.size() + 1) return {};
        
        // split into # of left blocks
        vector<string> res;
        string blockCnt = to_string(left);
        int index = 0;
        int cnt = 1;
        while (index < n) {
            int remain = limit - 3;
            remain -= digits(cnt);
            remain -= blockCnt.size();
            int extract = min(remain, n - index);
            string temp = message.substr(index, extract) + "<" + to_string(cnt) + "/" + blockCnt + ">";
            res.push_back(temp);
            index += extract;
            cnt++;
        }
        return res;
    }
};
