impl Solution {
    pub fn check_record(n: i32) -> i32 {
        let MOD = 1000000007usize;
        let mut dp: Vec<usize> = vec![1, 1, 0, 1, 0, 0];
        let mut temp_dp = dp.clone();

        for i in 1..n {
            temp_dp[0] = (dp[0] + dp[1] + dp[2]) % MOD;
            temp_dp[1] = dp[0];
            temp_dp[2] = dp[1];
            temp_dp[3] = dp.iter().sum::<usize>() % MOD;
            temp_dp[4] = dp[3];
            temp_dp[5] = dp[4];
            std::mem::swap(&mut dp, &mut temp_dp);
        }

        (dp.iter().sum::<usize>() % MOD) as i32
    }
}
