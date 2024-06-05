impl Solution {
    pub fn common_chars(words: Vec<String>) -> Vec<String> {
        let mut hash = vec![100; 26];
        for word in words {
            let cs = word.as_bytes();
            let mut hash_temp = vec![0; 26];
            for c in cs {
                hash_temp[(c - b'a') as usize] += 1;
            }
            for i in 0..26 {
                hash[i] = hash[i].min(hash_temp[i]);
            }
        }
        let mut res = Vec::new();
        for i in 0..26 {
            for _ in 0..hash[i] {
                res.push(((i as u8 + (b'a' as u8)) as char).to_string());
            }
        }
        res
    }
}
