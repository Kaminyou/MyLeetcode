impl Solution {
    pub fn min_patches(nums: Vec<i32>, n: i32) -> i32 {
        let mut sum: i64 = 0;
        let mut count = 0;
        for num in nums {
            while (sum + 1) < num as i64 {
                count += 1;
                sum += (sum + 1);
                if sum >= n as i64{
                    break;
                }
            }
            sum += num as i64;
            if sum >= n as i64 {
                break;
            }
        }
        while sum < n as i64 {
            sum += (sum + 1);
            count += 1;
        }
        return count;
    }
}
