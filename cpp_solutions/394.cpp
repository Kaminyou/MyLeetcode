class Solution {
public:
    string recursiveDecode(string& s, int& index) {
        string res = "";
        int multiply = 0;
        while (index < s.size()) {
            if (s[index] >= '0' && s[index] <= '9') {
                multiply = multiply * 10 + s[index] - '0';
                index++;
            }
            else if (s[index] == '[') {
                index++;
                string out = recursiveDecode(s, index);
                for (int k = 0; k < multiply; ++k) res += out;
                multiply = 0;
            } 
            else if (s[index] == ']') {
                index++;
                return res;
            }
            else {
                res.push_back(s[index]);
                index++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return recursiveDecode(s, index);
    }
};