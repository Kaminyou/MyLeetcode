class Solution {
public:
    int splitNum(int num) {
        vector<int> hash(10, 0);
        while (num) {
            hash[num % 10]++;
            num /= 10;
        }
        
        int num1 = 0;
        int num2 = 0;
        bool num1Turn = true;
        for (int i = 0; i < 10; ++i) {
            int count = hash[i];
            for (int j = 0; j < count; ++j) {
                if (num1Turn) {
                    num1 *= 10;
                    num1 += i;
                    num1Turn = false;
                }
                else {
                    num2 *= 10;
                    num2 += i;
                    num1Turn = true;
                }
            }
        }
        return num1 + num2;
    }
};