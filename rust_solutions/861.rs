impl Solution {
    pub fn matrix_score(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        for i in 0..m {
            if (grid[i][0] == 0) {
                for j in 0..n {
                    grid[i][j] ^= 1;
                }
            }
        }
        let mut res = 0;
        for j in 0..n {
            let mut cnt = 0;
            for i in 0..m {
                if grid[i][j] == 1 {
                    cnt += 1;
                }
            }
            cnt = cnt.max(m - cnt);
            res += cnt * (1 << (n - 1 - j));
        }
        return res as i32;
    }
}
