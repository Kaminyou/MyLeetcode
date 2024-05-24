impl Solution {
    pub fn max_score_words(words: Vec<String>, letters: Vec<char>, score: Vec<i32>) -> i32 {
        let mut count = [0; 26];
        for &c in letters.iter() { 
            count[(c as u8 - b'a') as usize] += 1;
        }
        let mut freqs = vec![[0; 27]; words.len()];
        for (i, s) in words.iter().enumerate() {
            for b in s.bytes() {
                let j = (b - b'a') as usize;
                freqs[i][j] += 1;
                freqs[i][26] += score[j];
            }
        }
        Self::backtracking(0, &mut count, &freqs)
    }
    fn backtracking(i: usize, count: &mut [i32; 26], freqs: &Vec<[i32; 27]>) -> i32 {
        if i == freqs.len() {
            return 0;
        }
        let mut ans = Self::backtracking(i + 1, count, freqs);
        if (0..26).all(|j| count[j] >= freqs[i][j]) {
            let mut acc = 0;
            for j in 0..26 {
                count[j] -= freqs[i][j];
            }
            let ans2 = Self::backtracking(i + 1, count, freqs);
            ans = ans.max(freqs[i][26] + ans2);
            for j in 0..26 {
                count[j] += freqs[i][j];
            }
        }
        ans
    }
}