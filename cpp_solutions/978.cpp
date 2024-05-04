class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1;
        int inc = 1;
        int dec = 1;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                dec = inc + 1;
                inc = 1;
            }
            else if (arr[i] < arr[i + 1]) {
                inc = dec + 1;
                dec = 1;
            }
            else {
                inc = 1;
                dec = 1;
            }
            res = max(res, max(inc, dec));
        }
        return res;
    }
};

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int index = 0;
        int res = 1;
        while (index + 1 < n) {
            if (arr[index + 1] > arr[index]) {
                int start = index;
                int right = index + 1;
                int sign = 1;
                res = max(res, 2);
                while (right + 1 < n) {
                    if (arr[right + 1] > arr[right] && sign == -1) {
                        right++;
                        res = max(res, right - start + 1);
                        sign = 1;
                    }
                    else if (arr[right + 1] < arr[right] && sign == 1) {
                        right++;
                        res = max(res, right - start + 1);
                        sign = -1;
                    }
                    else {
                        break;
                    }
                }
                index = right;
            }
            else if (arr[index + 1] < arr[index]) {
                int start = index;
                int right = index + 1;
                int sign = -1;
                res = max(res, 2);
                while (right + 1 < n) {
                    if (arr[right + 1] > arr[right] && sign == -1) {
                        right++;
                        res = max(res, right - start + 1);
                        sign = 1;
                    }
                    else if (arr[right + 1] < arr[right] && sign == 1) {
                        right++;
                        res = max(res, right - start + 1);
                        sign = -1;
                    }
                    else {
                        break;
                    }
                }
                index = right;
            }
            else {
                index++;
                res = max(res, 1);
            }
        }
        return res;
    }
};