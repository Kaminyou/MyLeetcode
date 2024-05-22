impl Solution {
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let n: usize = s.len();
        let mut dp: Vec<Vec<bool>> = vec![vec![false; n]; n];
        let chs: Vec<char> = s.chars().collect();
        for right in 0..n {
            for left in 0..=right {
                if chs[left] == chs[right] && (right - left <= 2 || dp[left + 1][right - 1]) {
                    dp[left][right] = true;
                }
            }
        }

        let mut path: Vec<String> = Vec::new();
        let mut paths: Vec<Vec<String>> = Vec::new();
        Self::backtracking(0, &mut path, &s, &dp, &mut paths);
        return paths;
    }
    fn backtracking(
        index: usize,
        path: &mut Vec<String>,
        s: &str,
        dp: &Vec<Vec<bool>>,
        paths: &mut Vec<Vec<String>>,
    ) {
        let n: usize = s.len();
        if index == n {
            paths.push(path.to_vec());
            return;
        }
        for i in index..n {
            if dp[index][i] {
                path.push(s[index..1 + i].to_owned());
                Self::backtracking(1 + i, path, s, dp, paths);
                path.pop();
            }
        }
    }
}
