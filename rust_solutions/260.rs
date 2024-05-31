impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let mut value = 0;
        for &num in &nums {
            value ^= num;
        }
        let diff = value & (-value);
        let mut x = 0;
        for &num in &nums {
            if diff & num != 0 {
                x ^= num;
            }
        }
        vec![value ^ x, x]
    }
}
