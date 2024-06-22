impl Solution {
    pub fn number_of_subarrays(nums: Vec<i32>, k: i32) -> i32 {
        let mut hash = std::collections::HashMap::new();
        hash.insert(0, 1);
        let n = nums.len();
        let mut cnt = 0;
        let mut res = 0;
        for i in 0..n {
            if (nums[i] & 1) == 1 {
                cnt += 1;
            }
            if let Some(&count) = hash.get(&(cnt - k)) {
                res += count;
            }
            *hash.entry(cnt).or_insert(0) += 1;
        }
        return res;
    }
}
