impl Solution {
    pub fn mincost_to_hire_workers(quality: Vec<i32>, wage: Vec<i32>, k: i32) -> f64 {
        let n = quality.len();
        let mut v = Vec::new();
        for i in 0..n {
            let r = wage[i] as f64 / quality[i] as f64;
            v.push((r, quality[i] as f64));
        }
        v.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());

        let mut pq = std::collections::BinaryHeap::new();
        let mut qs = 0.0;
        let mut ans = std::f64::MAX;

        for i in 0..n {
            qs += v[i].1;
            pq.push(v[i].1 as i64);
            if pq.len() > k as usize {
                qs -= pq.pop().unwrap() as f64;
            }
            if pq.len() == k as usize {
                ans = ans.min(qs * v[i].0);
            }
        }
        ans
    }
}
