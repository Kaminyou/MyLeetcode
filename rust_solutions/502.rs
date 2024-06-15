impl Solution {
    pub fn find_maximized_capital(k: i32, mut w: i32, profits: Vec<i32>, capital: Vec<i32>) -> i32 {
        let n = profits.len();
        let mut v = vec![];
        for i in 0..n {
            v.push((capital[i], profits[i]));
        }
        v.sort();
        
        let mut pq = std::collections::BinaryHeap::<i32>::new();
        let mut currentIdx = 0;
        for i in 0..k {
            while currentIdx < n && v[currentIdx].0 <= w {
                pq.push(v[currentIdx].1);
                currentIdx += 1;
            }
            let mut top = *(pq.peek().unwrap_or(&-1));
            if top >= 0 {
                w += top;
                pq.pop();
            }
            else {
                break;
            }
        }
        return w;
    }
}
