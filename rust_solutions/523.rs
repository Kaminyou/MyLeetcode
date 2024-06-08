impl Solution {
    pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
        let mut hash = std::collections::HashSet::new();
        let mut current = 0;
        let mut previous = 0;

        let n = nums.len();
        if n < 2 {
            return false;
        }
        for i in 0..n {
            current += nums[i];
            if i > 0 {
                hash.insert(previous % k);
                let key = current % k;
                if hash.contains(&key) {
                    return true;
                }
                previous += nums[i - 1];
            }
        }
        return false;
    }
}