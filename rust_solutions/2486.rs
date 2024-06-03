impl Solution {
    pub fn append_characters(s: String, t: String) -> i32 {
        let s_b = s.as_bytes();
        let t_b = t.as_bytes();
        let n = t.len();
        let mut idx: usize = 0;

        let m = s.len();
        for i in 0..m {
            if idx < n && s_b[i] == t_b[idx] {
                idx += 1;
            }
        }
        return (n - idx) as i32;
    }
}
