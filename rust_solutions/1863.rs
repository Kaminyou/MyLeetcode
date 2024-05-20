impl Solution {
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut res = 0;
        for i in 0..(1 << n) {
            let mut temp = 0;
            for j in 0..n {
                if (i & (1 << j)) > 0 {
                    temp ^= nums[j];
                }
            }
            res += temp;
        }
        return res;
    }
}
