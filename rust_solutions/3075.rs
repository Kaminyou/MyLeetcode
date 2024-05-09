impl Solution {
    pub fn maximum_happiness_sum(mut happiness: Vec<i32>, k: i32) -> i64 {
        let mut decr: i64 = 0;
        let mut sum: i64 = 0;
        happiness.sort_unstable();
        for v in happiness.into_iter().rev().take(k as usize) {
            sum += ((v as i64) - decr).max(0) as i64;
            decr += 1;
        }
        sum
    }
}
