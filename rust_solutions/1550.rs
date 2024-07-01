impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let mut cnt = 0;
        for num in arr {
            if (num & 1) == 1 {
                cnt += 1;
            }
            else {
                cnt = 0;
            }
            if cnt == 3 {
                return true;
            }
        }
        return false;
    }
}
