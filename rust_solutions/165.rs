impl Solution {
    pub fn compare_version(version1: String, version2: String) -> i32 {
        let mut r1 = version1.split('.').map(|s| s.parse().unwrap());
        let mut r2 = version2.split('.').map(|s| s.parse().unwrap());

        loop {
            match (r1.next(), r2.next()) {
                (Some(r1), r2) if r1 > r2.unwrap_or(0) => return 1,
                (r1, Some(r2)) if r1.unwrap_or(0) < r2 => return -1,
                (None, None) => return 0,
                _ => continue,
            }
        }
    }
}
