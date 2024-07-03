impl Solution {
    pub fn min_difference(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n <= 3 {
            return 0;
        }
        nums.sort();
        let mut min_val = i32::MAX;
        for i in 0..4 {
            min_val = i32::min(min_val, i32::abs(nums[i] - nums[i + (n - 4)]));
        }
        return min_val;
    }
}
