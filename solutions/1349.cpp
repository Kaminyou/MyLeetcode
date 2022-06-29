class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        
        // generate a mask for each row in seats
        vector<int> availableSeats(m + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if (seats[i - 1][j] == '.') {
                    availableSeats[i] = availableSeats[i] | (1 << j);
                }
            }
        }
        // dp table: [row, mask] the max students given row id and a mask
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));
        
        // init dp row 0
        for (int mask = 0; mask < (1 << n); mask++) dp[0][mask] = 0;
        
        // for each row
        for (int i = 1; i <= m; i++) {
            // for mask in the current row
            for (int mask = 0; mask < (1 << n); mask++) {
                // if the mask is now allowed according to the available seats -> continue
                if ((mask & availableSeats[i]) != mask) continue;
                // if the mask has two adjacent seats -> continue 
                if (mask & (mask << 1) || mask & (mask >> 1)) continue;
                
                // for mask in the prev row
                for (int prevMask = 0; prevMask < (1 << n); prevMask++) {
                    // if the previous mask does not exist -> continue
                    if (dp[i - 1][prevMask] == -1) continue;
                    
                    // if the previous mask has any seat diagonal to the current mask -> continue
                    if (((prevMask << 1) & mask) || ((prevMask >> 1) & mask)) continue;
                    
                    // update the dp table -> previous # of student + the # of 1 in the current mask
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][prevMask] + __builtin_popcount(mask));
                }
            }
        }
        return *max_element(dp[m].begin(), dp[m].end());
    }
};