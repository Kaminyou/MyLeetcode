class Solution {
public:
    const vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string convertHundred(int num) {
        if (num == 0) return "";
        // [1, 999]
        int a = num / 100;
        int b = num % 100;
        int c = num % 10;
        int d = b / 10;
        string res = "";
        if (a > 0) res += v1[a] + " Hundred";
        if (b == 0) return res;
        if (b < 20) res += (res.size() == 0 ? "" : " ") + v1[b];
        else {
            if (d > 1) res += (res.size() == 0 ? "" : " ") + v2[d];
            if (c > 0) res += (res.size() == 0 ? "" : " ") + v1[c];
        }
        return res;
        
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = "";
        vector<string> v3 = {"Thousand", "Million", "Billion"};
        res += convertHundred(num % 1000);
        num /= 1000;
        int index = 0;
        while (num) {
            string temp = convertHundred(num % 1000);
            if (temp.size() != 0) res = temp + " " + v3[index] + (res.size() == 0 ? "" : " ") + res;
            index++;
            num /= 1000;
        }
        return res;
    }
};