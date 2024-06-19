impl Solution {
    pub fn criteria(bloom_day: &Vec<i32>, m: i32, k: i32, days: i32) -> bool {
        let n = bloom_day.len();
        let mut temp_cnt = 0;
        let mut cnt = 0;
        for i in 0..n {
            if bloom_day[i] <= days {
                temp_cnt += 1;
            }
            else {
                temp_cnt = 0;
            }
            if temp_cnt == k {
                cnt += 1;
                temp_cnt = 0;
            }
        }
        return cnt >= m;
    }
    pub fn min_days(bloom_day: Vec<i32>, m: i32, k: i32) -> i32 {
        let n = bloom_day.len();
        if m as i64 * k as i64 > n as i64 {
            return -1;
        }
        let mut left = 0;
        let mut right = i32::MAX;
        while left < right {
            let mid = left + (right - left) / 2;
            if Solution::criteria(&bloom_day, m, k, mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
}

