impl Solution {
    pub fn special_array(nums: Vec<i32>) -> i32 {
        let (mut start, mut end) = (0, (nums.len() + 1) as i32);

        while start < end {
            let mid = start + (end - start) / 2;
            let count = nums.iter().filter(|&x| *x >= mid).count() as i32;
            if count == mid {
                return mid;
            }
            if count < mid {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        -1
    }
}