impl Solution {
    pub fn is_n_straight_hand(hand: Vec<i32>, group_size: i32) -> bool {
        let mut t = std::collections::BTreeMap::new();
        for n in hand {
            *t.entry(n).or_insert(0) += 1;
        }
        while !t.is_empty() {
            let (&k, &v) = t.first_key_value().unwrap();
            for i in 0..group_size {
                if !t.contains_key(&(k + i)) {
                    return false;
                }
                if t[&(k + i)] == 1 {
                    t.remove(&(k + i));
                }
                else {
                    t.insert(k + i, t[&(k + i)] - 1);
                }
            }
        }
        return true;
    }
}
