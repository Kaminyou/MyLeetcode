impl Solution {
    pub fn num_steps(s: String) -> i32 {
        let n = s.len();
        let s_b = s.as_bytes();

        let mut carry = 0;
        let mut res = 0;
        
        for i in (1..n).rev() {
            res += 1;
            if s_b[i] - ('0' as u8) + (carry as u8) == 1 {
                carry = 1;
                res += 1;
            }
        }
        return res + carry;
    }
}
