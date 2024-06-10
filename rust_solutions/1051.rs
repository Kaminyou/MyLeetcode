impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut ordered_heights = heights.clone();
        ordered_heights.sort_unstable();
        let n = heights.len();
        let mut res = 0;
        for i in 0..n {
            if heights[i] != ordered_heights[i] {
                res += 1;
            }
        }
        res
    }
}
