impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut cnt = [0; 3];
        for &num in nums.iter() {
            cnt[num as usize] += 1;
        }

        let mut index = 0;
        for i in 0..3 {
            while (cnt[i] > 0) {
                nums[index as usize] = i as i32;
                index += 1;
                cnt[i] -= 1;
            }
        }
    }
}
