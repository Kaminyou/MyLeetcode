impl Solution {
    pub fn maximum_safeness_factor(grid: Vec<Vec<i32>>) -> i32 {
        let (n, mut grid) = (grid.len(), grid);
        let mut q = std::collections::VecDeque::new();

        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 0 {
                    grid[i][j] = -1;
                } else {
                    grid[i][j] = 0;
                    q.push_back((0, i, j));
                }
            }
        }

        let dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];

        while let Some((val, i, j)) = q.pop_front() {
            for d in &dirs {
                let (u, v) = (i as i32 + d[0], j as i32 + d[1]);
                if u < 0 || u == n as i32 || v < 0 || v == n as i32 {
                    continue;
                }
                let (u, v) = (u as usize, v as usize);
                if grid[u][v] != -1 {
                    continue;
                }
                grid[u][v] = val + 1;
                q.push_back((val + 1, u , v));
            }
        }

        let mut pq = std::collections::BinaryHeap::new();
        let mut dist = vec![vec![-1; n]; n];

        dist[0][0] = grid[0][0];
        pq.push((grid[0][0], 0, 0));

        while let Some((val, i, j)) = pq.pop() {
            if i == n - 1 && j == n - 1 {
                return val;
            }
            for d in &dirs {
                let (u, v) = (i as i32 + d[0], j as i32 + d[1]);
                if u < 0 || u == n as i32 || v < 0 || v == n as i32 {
                    continue;
                }
                let (u, v) = (u as usize, v as usize);
                if dist[u][v] != -1 {
                    continue;
                }
                dist[u][v] = grid[u][v].min(dist[i][j]);
                pq.push((dist[u][v], u, v));
            }
        }
        0
    }
}
