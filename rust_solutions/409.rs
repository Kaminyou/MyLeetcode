impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut hash = std::collections::HashMap::new();
        for k in s.chars() {
            let val = hash.entry(k).or_insert(0);
            *val += 1;
        }
        let mut has_odd = false;
        let sum: i32 = hash.into_iter().fold(0, |acc, (_, x)| {
            has_odd = has_odd || x % 2 ==1;
            acc + (x / 2) * 2
        });
        sum + if has_odd {1} else {0}
    }
}
