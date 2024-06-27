impl Solution {
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        let n = edges.len();
        let mut indegrees = vec![0; n + 2];
        for i in 0..n {
            indegrees[edges[i][0] as usize] += 1;
            indegrees[edges[i][1] as usize] += 1;
        }
        for i in 1..n + 2 {
            if indegrees[i] == n {
                return i as i32;
            }
        }
        return -1;
    }
}

