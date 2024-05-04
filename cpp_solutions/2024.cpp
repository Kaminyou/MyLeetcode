class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res = 0;
        int left = 0;
        int right = 0;
        int count = 0;
        // to flip T to F
        for (; right < answerKey.size(); ++right) {
            if (answerKey[right] == 'T') count++;
            if (count > k) {
                if (answerKey[left] == 'T') count--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        
        // to flip F to T
        right = left = count = 0;
        for (; right < answerKey.size(); ++right) {
            if (answerKey[right] == 'F') count++;
            if (count > k) {
                if (answerKey[left] == 'F') count--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};