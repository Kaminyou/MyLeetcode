impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut res: Vec<Vec<i32>> = vec![];

        for i in 0..2_u32.pow(n as u32) {
            let mut subset = vec![];
            for j in 0..n {
                if (i & (1 << j)) > 0 {
                    subset.push(nums[j]);
                }
            }
            res.push(subset);
        }
        return res;
    }
}
