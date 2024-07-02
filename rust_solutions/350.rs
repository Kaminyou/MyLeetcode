impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::new();
        let mut cnt = vec![0; 1001];

        for num in nums1 {
            cnt[num as usize] += 1;
        }
        for num in nums2 {
            if cnt[num as usize] > 0 {
                res.push(num);
                cnt[num as usize] -= 1;
            }
        }
        return res;
    }
}

