impl Solution {
    pub fn min_increment_for_unique(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let mut res = 0;
        let mut current = -1;
        let n = nums.len();
        for i in 0..n {
            if nums[i] > current {
                current = nums[i];
            }
            else {
                current += 1;
                res += (current - nums[i]);
                nums[i] = current;
            }
        }
        res
    }
}

