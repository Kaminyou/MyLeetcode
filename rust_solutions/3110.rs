impl Solution {
    pub fn score_of_string(s: String) -> i32 {
        let mut res: i32 = 0;
        let n = s.len();
        let s_b = s.as_bytes();

        for i in 0..n - 1 {
            res += u8::abs_diff(s_b[i], s_b[i + 1]) as i32;
        }
        return res;
    }
}
