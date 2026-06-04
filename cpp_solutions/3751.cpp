class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int nums[6];
        int res = 0;
        for (int curr = num1; curr <= num2; ++curr) {
            int num = curr;
            int index = 0;
            while (num) {
                nums[index] = num % 10;
                num /= 10;
                index++;
            }
            if (index < 3) continue;
            for (int i = 1; i < index - 1; ++i) {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) res++;
                if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) res++;
            }
        }
        return res;
    }
};
