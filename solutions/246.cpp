class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            bool flag = false;
            if (num[left] == '9' && num[right] == '6') flag = true;
            else if (num[left] == '8' && num[right] == '8') flag = true;
            else if (num[left] == '6' && num[right] == '9') flag = true;
            else if (num[left] == '1' && num[right] == '1') flag = true;
            else if (num[left] == '0' && num[right] == '0') flag = true;
            if (!flag) return false;
            left++;
            right--;
        }
        if (n & 1) {
            if (num[left] != '0' && num[left] != '1' && num[left] != '8') return false;
        }
        return true;
    }
};