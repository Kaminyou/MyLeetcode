class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int leftLower = 0;
            int leftHigher = 0;
            int rightLower = 0;
            int rightHigher = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    leftLower++;
                }
                else if (rating[j] > rating[i]) {
                    leftHigher++;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (rating[j] < rating[i]) {
                    rightLower++;
                }
                else if (rating[j] > rating[i]) {
                    rightHigher++;
                }
            }
            res += leftLower * rightHigher + leftHigher * rightLower;
        }
        return res;
    }
};