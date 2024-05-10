impl Solution {
    pub fn kth_smallest_prime_fraction(arr: Vec<i32>, k: i32) -> Vec<i32> {
        let n = arr.len();
        let mut left = 0.0;
        let mut right = 1.0;

        while left < right {
            let mid = left + (right - left) / 2.0;
            let mut count = 0;
            let mut p = 0;
            let mut q = 0;
            let mut j = 1;
            let mut max_frac = 0.0;
            for i in 0..(n - 1) {
                while j < n && (arr[i] as f64) > mid * (arr[j] as f64) {
                    j += 1;
                }
                count += n - j;
                if j == n {
                    break;
                }
                let frac = (arr[i] as f64) / (arr[j] as f64);
                if frac > max_frac {
                    p = i;
                    q = j;
                    max_frac = frac;
                }
            }
            if count as i32 == k {
                return vec![arr[p], arr[q]];
            } else if count as i32 > k {
                right = mid;
            } else {
                left = mid;
            }
        }
        vec![]
    }
}
