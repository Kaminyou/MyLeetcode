impl Solution {
    fn backtracking(index: usize, mask: i32, nums: &Vec<i32>, k: i32) -> i32 {
        if index == nums.len() {
            return (mask > 0) as i32;
        }
        let skip = Self::backtracking(index + 1, mask, nums, k);
        let mut can_use: bool = true;
        for i in 0..index {
            if (mask & (1 << i)) > 0 && i32::abs(nums[i] - nums[index]) == k {
                can_use = false;
            }
        }
        if can_use {
            return skip + Self::backtracking(index + 1, mask | (1 << index), nums, k);
        }
        return skip;
    }
    pub fn beautiful_subsets(nums: Vec<i32>, k: i32) -> i32 {
        return Self::backtracking(0, 0, &nums, k);
    }
}
