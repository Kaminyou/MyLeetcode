impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, minutes: i32) -> i32 {
        let n = customers.len() as i32;
        let mut accum = 0;
        for i in 0..n {
            if grumpy[i as usize] == 0 {
                accum += customers[i as usize];
            }
        }

        let mut maxSatisfied = accum;
        for i in 0..minutes - 1 {
            if grumpy[i as usize] == 1 {
                accum += customers[i as usize];
            }
        }

        for i in minutes - 1..n {
            if grumpy[i as usize] == 1 {
                accum += customers[i as usize];
            }
            maxSatisfied = i32::max(maxSatisfied, accum);
            if grumpy[(i - minutes + 1) as usize] == 1 {
                accum -= customers[(i - minutes + 1) as usize];
            }
        }
        maxSatisfied
    }
}

