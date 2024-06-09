impl Solution {
    pub fn subarrays_div_by_k(nums: Vec<i32>, k: i32) -> i32 {
        let mut mp = std::collections::HashMap::new();
        let mut res: i32 = 0;
        let mut sum: i32 = 0;

        mp.insert(0, 1);

        for num in nums {
            sum += num;
            let m = ((sum % k) + k) % k;
            if let Some(count) = mp.get(&m) {
                res += count;
            }
            *mp.entry(m).or_insert(0) += 1;
        }
        return res;
    }
}
