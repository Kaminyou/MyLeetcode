impl Solution {
    pub fn maximum_value_sum(nums: Vec<i32>, k: i32, edges: Vec<Vec<i32>>) -> i64 {
        let mut sum: i64 = 0;
        let mut cnt: i32 = 0;
        let mut sacrifice: i64 = i64::MAX;

        for &num in &nums {
            let num = num as i64;
            let num_xor = num ^ k as i64;
            sum += num.max(num_xor);

            cnt += (num_xor > num) as i32;
            sacrifice = sacrifice.min((num - num_xor).abs());
        }
        if cnt % 2 == 1 {
            return sum - sacrifice;
        }
        return sum;
    }
}
