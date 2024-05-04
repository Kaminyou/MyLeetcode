impl Solution {
    pub fn reverse_prefix(word: String, ch: char) -> String {
        let index = word.find(ch);
        if index.is_none() {
            return word;
        }
        let index = index.unwrap();
        word[..index + 1].chars().rev().chain(word[index + 1..].chars()).collect()
    }
}
