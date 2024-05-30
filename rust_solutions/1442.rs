impl Solution {
    pub fn count_triplets(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut prefix = vec![0; n + 1];
        let mut curr: i32 = 0;
        for i in 0..n {
            curr ^= arr[i];
            prefix[i + 1] = curr;
        }
        let mut res: i32 = 0;
        for i in 0..n {
            for j in i + 1..n {
                if (prefix[j + 1] ^ prefix[i]) == 0 {
                    res += (j - i) as i32;
                }
            }
        }
        return res;
    }
}
