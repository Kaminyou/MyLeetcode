impl Solution {
    pub fn max_profit_assignment(difficulty: Vec<i32>, profit: Vec<i32>, mut worker: Vec<i32>) -> i32 {
        let n = difficulty.len();
        let mut v = vec![];

        for i in 0..n {
            v.push((difficulty[i], profit[i]));
        }

        v.sort();

        let mut res = 0;
        let mut max_profit = 0;
        let mut idx = 0;
        worker.sort();
        let m = worker.len();
        for i in 0..m {
            while idx < n && worker[i] >= v[idx].0 {
                max_profit = i32::max(max_profit, v[idx].1);
                idx += 1;
            }
            res += max_profit;
        }
        return res;
    }
}
