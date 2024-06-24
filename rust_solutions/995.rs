impl Solution {
    pub fn min_k_bit_flips(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut diff = vec![0; n + 1];
        let mut count = 0;
        let mut flips = 0;
        for i in 0..n {
            flips += diff[i];
            if nums[i] + (flips & 1) as i32 == 1 {
                continue;
            }
            if i as i32 + k - 1 >= n as i32 {
                return -1;
            }
            flips += 1;
            diff[i + k as usize] -= 1;
            count += 1;
        }
        return count;
    }
}

