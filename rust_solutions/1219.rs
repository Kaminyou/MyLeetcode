impl Solution {
    pub fn get_maximum_gold(grid: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (grid.len(), grid[0].len());

        let mut grid_copy = grid.clone();
        let mut_grid: &mut Vec<Vec<i32>> = &mut grid_copy;
        fn dfs(grid: &mut Vec<Vec<i32>>, r: usize, c: usize) -> i32 {
            let (m, n) = (grid.len(), grid[0].len());
            let current = grid[r][c];
            let mut max_value = current;
            grid[r][c] = 0;
            for (x, y) in [(r+1, c), (r-1, c), (r, c+1), (r, c-1)] {
                if x < 0 || x >= m || y < 0 || y >= n {
                    continue;
                }
                let x = x as usize;
                let y = y as usize;
                if grid[x][y] == 0 {
                    continue;
                }
                max_value = max_value.max(current + dfs(grid, x, y));
            }
            grid[r][c] = current;
            max_value
        }

        let mut res = 0;
        for r in 0..m {
            for c in 0..n {
                if grid[r][c] != 0 {
                    res = res.max(dfs(mut_grid, r, c));
                }
            }
        }
        res
    }
}
