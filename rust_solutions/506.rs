impl Solution {
    pub fn find_relative_ranks(mut score: Vec<i32>) -> Vec<String> {
        let mut d = std::collections::HashMap::new();
        for i in 0..score.len() {
            d.insert(score[i], i);
        }
        score.sort();
        score.reverse();
        let mut ret = vec!["".to_string(); score.len()];
        for i in 0..score.len() {
            let rank = match i {
                0 => "Gold Medal".to_owned(),
                1 => "Silver Medal".to_owned(),
                2 => "Bronze Medal".to_owned(),
                _ => (i + 1).to_string(),
            };
            ret[*d.get(&score[i]).unwrap()] = rank;
        }
        ret
    }
}
