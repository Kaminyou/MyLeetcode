/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int currIdx = 0;
    char buf4[4];
    int left = 0;
    queue<char> q;
    int read(char *buf, int n) {
        int res = 0;
        while (left > 0 && n > 0) {
            buf[res] = q.front();
            q.pop();
            left--;
            n--;
            res++;
            currIdx++;
        }
        while (n > 0) {
            int load = read4(buf4);
            int maxVal = min(n, load);
            if (maxVal == 0) return res;
            for (int i = 0; i < maxVal; ++i) {
                buf[res] = buf4[i];
                currIdx++;
                res++;
            }
            n -= maxVal;
            while (load > maxVal) {
                q.push(buf4[maxVal]);
                left++;
                maxVal++;
            }
        }
        return res;
    }
};