impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        let half = (c as f32).sqrt().floor() as i32;
        for a in 0..half + 1 {
            let left = c - a * a;
            let b = (left as f32).sqrt().floor() as i32;
            if a * a + b * b == c {
                return true;
            }
        }
        return false;
    }
}
