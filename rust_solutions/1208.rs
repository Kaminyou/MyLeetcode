impl Solution {
    pub fn equal_substring(s: String, t: String, max_cost: i32) -> i32 {
        let n = s.len();
        let mut diff = vec![0; n];

        let sbytes = s.as_bytes();
        let tbytes = t.as_bytes();

        for i in 0..n {
            diff[i] = (u8::abs_diff(sbytes[i], tbytes[i])) as usize;
        }

        let mut curr: i32 = 0;
        let mut left: usize = 0;
        let mut res: i32 = 0;
        for right in 0..n {
            curr += diff[right] as i32;
            while curr > max_cost {
                curr -= diff[left] as i32;
                left += 1;
            }
            res = i32::max(res, (right - left + 1) as i32);
        }
        return res;
    }
}
