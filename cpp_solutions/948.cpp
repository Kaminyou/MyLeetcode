class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0;
        int right = tokens.size() - 1;
        int n = tokens.size();
        int score = 0;
        int res = 0;
        while (left <= right) {
            while (left < n && tokens[left] <= power) {
                power -= tokens[left];
                score++;
                left++;
            }
            res = max(res, score);
            if (left <= right && score > 0) {
                score--;
                power += tokens[right];
                right--;
            }
            else break;
        }
        return res;
    }
};