use std::collections::BinaryHeap;
use std::cmp::max;

impl Solution {
    pub fn longest_subarray(nums: Vec<i32>, limit: i32) -> i32 {
        let mut max_q = BinaryHeap::from([(nums[0], 0)]);
        let mut min_q = BinaryHeap::from([(-nums[0], 0)]);

        let mut m = 1;
        let mut left = 0;
        for right in 1..nums.len() {
            max_q.push((nums[right], right));
            min_q.push((-nums[right], right));

            let mut max_t = max_q.peek().unwrap().clone();
            let mut min_t = min_q.peek().unwrap().clone();

            let mut d = max_t.0 + min_t.0;

            while d > limit {
                if min_t.1 < max_t.1 {
                    min_q.pop();

                    if left <= min_t.1 {
                        left = min_t.1 + 1;
                    }
                }
                else {
                    max_q.pop();
                    if left <= max_t.1 {
                        left = max_t.1 + 1;
                    }
                }
                max_t = max_q.peek().unwrap().clone();
                min_t = min_q.peek().unwrap().clone();

                d = max_t.0 + min_t.0;
            }
            m = max(m, right - left + 1);
        }
        return m as i32;
    }
}
