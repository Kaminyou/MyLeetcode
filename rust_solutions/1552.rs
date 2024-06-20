impl Solution {
    pub fn criteria(position: &Vec<i32>, m: i32, interval: i32) -> bool {
        let n = position.len();
        let mut current = i32::MIN;
        let mut cnt = 0;
        for &pos in position {
            if pos >= current + interval {
                current = pos;
                cnt += 1;
            }
        }
        cnt >= m
    }
    pub fn max_distance(mut position: Vec<i32>, m: i32) -> i32 {
        position.sort();
        let mut left = 0;
        let mut right = i32::MAX;
        while left < right {
            let mid = left + (right - left) / 2;
            if !Solution::criteria(&position, m, mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        left - 1
    }
}

