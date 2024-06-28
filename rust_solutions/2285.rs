impl Solution {
    pub fn maximum_importance(n: i32, roads: Vec<Vec<i32>>) -> i64 {
        let mut indegrees = vec![0; n as usize];
        let m = roads.len();
        for i in 0..m {
            indegrees[roads[i][0] as usize] += 1;
            indegrees[roads[i][1] as usize] += 1;
        }
        indegrees.sort();
        let mut res: i64 = 0;
        for i in 0..n {
            res += (indegrees[i as usize] as i64) * ((i + 1) as i64);
        }
        res
    }
}

