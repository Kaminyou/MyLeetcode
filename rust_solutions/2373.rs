impl Solution {
    pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m, n) = (grid.len(), grid[0].len());
        let mut ret = vec![vec![0; n - 2]; m - 2];
        
        fn find(grid: &Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
            let mut ret = grid[i][j];
            for r in [i - 1, i, i + 1] {
                for c in [j - 1, j, j + 1] {
                    ret = ret.max(grid[r][c]);
                }
            }
            return ret;
        }
        for i in 0..m - 2 {
            for j in 0..n - 2 {
                ret[i][j] = find(&grid, i + 1, j + 1);
            }
        }
        ret
    }
}